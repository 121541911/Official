
#include "windows.h"

#include "WindTradeAPI.h"
#pragma comment(lib,"WindTradeAPI.lib") 

namespace
{
const char* p_ErrMsg = 0;
long        long_out;
const char* p_out;
double      double_out;

long        LogonID;
}

void WINAPI ResponseCallback( long ResponseID );

void Test_Login();
void Test_Order();
void Test_CapitalQry();
void Test_PositionQry();
void Test_OrderQry();
void Test_TradeQry();

void Test_login_report(long ResponseID);
void Test_Order_report(long ResponseID);
void Test_CapitalQry_report(long ResponseID);
void Test_PositionQry_report(long ResponseID);
void Test_OrderQry_report(long ResponseID);
void Test_Cancel_report(long ResponseID);
void Test_TradeQry_report(long ResponseID);
void Test_DepartmentQry_report(long ResponseID);
void Test_ReckoningQry_report(long ResponseID);
void Test_AccountQry_report(long ResponseID);

int main()
{
    WTradeInit(&ResponseCallback);

    WTradeAuthorize("��Wind��֤ID","��Wind��֤password");

    Test_Login();

    Test_Order();

    Test_CapitalQry();
    Test_PositionQry();
    Test_OrderQry();
    Test_TradeQry();


    return  0;
}

void WINAPI ResponseCallback( long ResponseID )
{
    const char* p_out = 0;
    long FunID;
    long ErrID;
    
    WTradeRespGetLong(ResponseID,0,W_FuncID,&FunID);
    WTradeRespGetLong(ResponseID,0,W_ErrID,&ErrID);
    WTradeRespGetStr(ResponseID,0,W_ErrMsg,&p_out);

    if(ErrID==WD_ERRID_SUCCESS)
    {
        switch(FunID)
        {
        case WD_FUNCID_LOGON: 
            Test_login_report(ResponseID);
            break;
        case WD_FUNCID_ORDER: 
            Test_Order_report(ResponseID);
            break;
        case WD_FUNCID_CAPITAL_QRY: 
            Test_CapitalQry_report(ResponseID);
            break;
        case WD_FUNCID_POSITION_QRY: 
            Test_PositionQry_report(ResponseID);
            break;
        case WD_FUNCID_ORDER_QRY: 
            Test_OrderQry_report(ResponseID);
            break;
        case WD_FUNCID_CANCEL: 
            Test_Cancel_report(ResponseID);
            break;
        case WD_FUNCID_TRADE_QRY: 
            Test_TradeQry_report(ResponseID);
            break;
        case WD_FUNCID_DEPARTMENT_QRY: 
            Test_DepartmentQry_report(ResponseID);
            break;
        case WD_FUNCID_ACCOUNT_QRY: 
            Test_AccountQry_report(ResponseID);
            break;
        }
    }
}

void Test_Login()
{
    long ResponseID = 0;
    int RequestID = WTradeCreateReq();
    
    if( RequestID )
    {
        WTradeReqSetLong(RequestID,W_FuncID,WD_FUNCID_LOGON);        //���ܺ�         
		WTradeReqSetStr(RequestID,W_BrokerID,"��ȯ��BrokerID");      //ȯ�̴���        
        WTradeReqSetStr(RequestID,W_DepartmentID,0);                 //Ӫҵ������        
        WTradeReqSetStr(RequestID,W_LogonAccount, "���ʽ��˺�");     //�˺�
        WTradeReqSetStr(RequestID,W_Password,"������");              //�˺�����  
        WTradeReqSetLong(RequestID,W_AccountType,/*�˺�����,����:*/WD_ACCOUNT_SPSH);   //�˺�����  

        WTradeSendReqSync(RequestID,&ResponseID);
    }

    Test_login_report(ResponseID);    
}

void Test_login_report(long ResponseID)
{
    if( ResponseID )
    {        
        WTradeRespGetLong(ResponseID,0,W_FuncID,&long_out);
        WTradeRespGetLong(ResponseID,0,W_ErrID,&long_out);
        WTradeRespGetStr(ResponseID,0,W_ErrMsg,&p_out);
    
        if( long_out == WD_ERRID_SUCCESS )
        {
            WTradeRespGetLong(ResponseID,0,W_RequestID,&long_out);
            WTradeRespGetLong(ResponseID,0,W_LogonID,&LogonID);
        }

		WTradeBuffRelease(ResponseID);	//ʹ�ú��ͷŻر�����
    }
}

void Test_Order()
{
    long ResponseID = 0;
    int RequestID = WTradeCreateReq();

    WTradeReqSetLong(RequestID,W_LogonID,LogonID);
    WTradeReqSetLong(RequestID,W_FuncID,WD_FUNCID_ORDER);       //���ܺ�     

    WTradeReqSetLong(RequestID,W_MarketType,WD_MARKET_CFE);      //�г�����    
    WTradeReqSetStr(RequestID,W_SecurityCode,"IF1308");         //֤ȯ����    
               

    WTradeReqSetLong(RequestID,W_OrderVolume,1);                //ί������    
    WTradeReqSetDouble(RequestID,W_OrderPrice,2300.0);          //ί�м۸�    
    WTradeReqSetLong(RequestID,W_OrderType,WD_OrderType_LMT);	//�۸�ί�з�ʽ    
    WTradeReqSetLong(RequestID,W_TradeSide,WD_TradeSide_Buy);
    WTradeReqSetLong(RequestID,W_HedgeType,WD_HedgeType_SPEC);

    WTradeSendReqAsyn(RequestID);
}        

void Test_Order_report(long ResponseID)
{
    if( ResponseID )
    {
        WTradeRespGetLong(ResponseID,0,W_FuncID,&long_out);   
        WTradeRespGetLong(ResponseID,0,W_ErrID,&long_out);
        WTradeRespGetStr(ResponseID,0,W_ErrMsg,&p_out);

        WTradeRespGetLong(ResponseID,0,W_MarketType,&long_out);
        WTradeRespGetStr(ResponseID,0,W_OrderNumber,&p_out);


		WTradeBuffRelease(ResponseID);	//ʹ�ú��ͷŻر�����
    }
}

void Test_Cancel(long MarketType,const char* OrderNumber)
{
    int RequestID = WTradeCreateReq();

    WTradeReqSetLong(RequestID,W_LogonID,LogonID);
    WTradeReqSetLong(RequestID,W_FuncID,WD_FUNCID_CANCEL);      //���ܺ�      
    WTradeReqSetLong(RequestID,W_MarketType,MarketType);
    WTradeReqSetStr(RequestID,W_OrderNumber,OrderNumber);

    WTradeSendReqAsyn(RequestID);
}

void Test_Cancel_report(long ResponseID)
{
    if(ResponseID)
    {
        WTradeRespGetLong(ResponseID,0,W_FuncID,&long_out);  
        WTradeRespGetLong(ResponseID,0,W_RequestID,&long_out);   
        WTradeRespGetLong(ResponseID,0,W_ErrID,&long_out); 
        WTradeRespGetStr(ResponseID,0,W_ErrMsg,&p_out);


		WTradeBuffRelease(ResponseID);	//ʹ�ú��ͷŻر�����
    }
}    

void Test_CapitalQry()
{
    long ResponseID = 0;
    int RequestID = WTradeCreateReq();

    WTradeReqSetLong(RequestID,W_LogonID,LogonID);
    WTradeReqSetLong(RequestID,W_FuncID,WD_FUNCID_CAPITAL_QRY);      //���ܺ�

    WTradeSendReqSync(RequestID,&ResponseID);
    
    Test_CapitalQry_report(ResponseID);
}

void Test_CapitalQry_report(long ResponseID)
{
    if(ResponseID)
    {
        WTradeRespGetLong(ResponseID,0,W_FuncID,&long_out);    
        WTradeRespGetLong(ResponseID,0,W_RequestID,&long_out);
        WTradeRespGetLong(ResponseID,0,W_ErrID,&long_out);
        WTradeRespGetStr(ResponseID,0,W_ErrMsg,&p_out);
    
        WTradeRespGetLong(ResponseID,0,W_ResponseCount,&long_out);			//Ӧ��ļ�¼����                 

        WTradeRespGetStr(ResponseID,0,W_Customer,&p_out);	                //�ͻ���                     
        WTradeRespGetStr(ResponseID,0,W_AssetAccount,&p_out);	            //�ʽ��˺�                    
        WTradeRespGetStr(ResponseID,0,W_DepartmentID,&p_out);	            //Ӫҵ��ID                   
        WTradeRespGetStr(ResponseID,0,W_MoneyType,&p_out);					//��������                    
        WTradeRespGetStr(ResponseID,0,W_Remark,&p_out);						//˵�� 

        //Stock
        WTradeRespGetDouble(ResponseID,0,W_AvailableFund,&double_out);		//�ʽ����                    
        WTradeRespGetDouble(ResponseID,0,W_BalanceFund,&double_out);	    //�ʽ����                    
        WTradeRespGetDouble(ResponseID,0,W_SecurityValue,&double_out);		//�ֲ���ֵ�ʲ�                  
        WTradeRespGetDouble(ResponseID,0,W_FundAsset,&double_out);			//�ʽ��ʲ�                    
        WTradeRespGetDouble(ResponseID,0,W_TotalAsset,&double_out);			//���ʲ�                     
        WTradeRespGetDouble(ResponseID,0,W_Profit,&double_out);				//��ӯ��                     
        WTradeRespGetDouble(ResponseID,0,W_FundFrozen,&double_out);			//�����ʽ�                    
        WTradeRespGetDouble(ResponseID,0,W_OtherFund,&double_out);			//�����ʽ�                    
        WTradeRespGetDouble(ResponseID,0,W_BuyFund,&double_out);	        //����������                  
        WTradeRespGetDouble(ResponseID,0,W_SellFund,&double_out);	        //�����������                  
                   
    
        //Future
        WTradeRespGetDouble(ResponseID,0,W_FetchFund,&double_out);			//��ȡ�ʽ�                    
        WTradeRespGetDouble(ResponseID,0,W_ExerciseMargin,&double_out);		//��Լ��֤��                   
        WTradeRespGetDouble(ResponseID,0,W_RealFrozenMarginA,&double_out);	//���տ���Ԥ������               
        WTradeRespGetDouble(ResponseID,0,W_RealFrozenMarginB,&double_out);	//���տ���Ԥ���ᱣ֤��ͷ���          
        WTradeRespGetDouble(ResponseID,0,W_HoldingProfit,&double_out);		//����ӯ��                    
        WTradeRespGetDouble(ResponseID,0,W_TotalFloatProfit,&double_out);	//�ܸ���ӯ��                   
        WTradeRespGetDouble(ResponseID,0,W_InitRightsBalance,&double_out);	//�ڳ��ͻ�Ȩ��                  
        WTradeRespGetDouble(ResponseID,0,W_CurrRightsBalance,&double_out);	//�ͻ�Ȩ��                    
        WTradeRespGetDouble(ResponseID,0,W_FloatRightsBal,&double_out);		//�����ͻ�Ȩ��                  
        WTradeRespGetDouble(ResponseID,0,W_RealDrop,&double_out);	        //����ƽ��ӯ��                  
        WTradeRespGetDouble(ResponseID,0,W_RealDrop_Float,&double_out);		//����ƽ��ӯ��                  
        WTradeRespGetDouble(ResponseID,0,W_FrozenFare,&double_out);			//�������                    
        WTradeRespGetDouble(ResponseID,0,W_CustomerMargin,&double_out);		//�ͻ���֤��                       
        WTradeRespGetDouble(ResponseID,0,W_RealOpenProfit,&double_out);		//���п���ӯ��                  
        WTradeRespGetDouble(ResponseID,0,W_FloatOpenProfit,&double_out);	//��������ӯ��                  
        WTradeRespGetDouble(ResponseID,0,W_Interest,&double_out);	        //Ԥ����Ϣ  


		WTradeBuffRelease(ResponseID);	//ʹ�ú��ͷŻر�����
    }   
}

void Test_PositionQry()
{
    long ResponseID = 0;
    int RequestID = WTradeCreateReq();

    WTradeReqSetLong(RequestID,W_LogonID,LogonID);
    WTradeReqSetLong(RequestID,W_FuncID,WD_FUNCID_POSITION_QRY);      //���ܺ�   

    WTradeSendReqSync(RequestID,&ResponseID);

    Test_PositionQry_report(ResponseID);
}

void Test_PositionQry_report(long ResponseID)
{
    if(ResponseID)
    {
        WTradeRespGetLong(ResponseID,0,W_FuncID,&long_out);      
        WTradeRespGetLong(ResponseID,0,W_RequestID,&long_out);
        WTradeRespGetLong(ResponseID,0,W_ErrID,&long_out);
        WTradeRespGetStr(ResponseID,0,W_ErrMsg,&p_out);

        long record_count = 0;
        WTradeRespGetLong(ResponseID,0,W_ResponseCount,&record_count);		//Ӧ��ļ�¼���� 

        for( int i=0; i<record_count; ++i )
        {
            WTradeRespGetStr(ResponseID,i,W_Customer,&p_out);	            //�ͻ���                                    
            WTradeRespGetStr(ResponseID,i,W_AssetAccount,&p_out);           //�ʽ��˺�                                   
            WTradeRespGetStr(ResponseID,i,W_MarketType,&p_out);	            //֤ȯ�г�                                   
            WTradeRespGetStr(ResponseID,i,W_Shareholder,&p_out);	        //�ɶ�����                                   
            WTradeRespGetStr(ResponseID,i,W_SecurityCode,&p_out);	        //֤ȯ����                                   
            WTradeRespGetStr(ResponseID,i,W_SecurityName,&p_out);	        //֤ȯ����                                   
            WTradeRespGetStr(ResponseID,i,W_DepartmentID,&p_out);	        //����Ӫҵ��                                  
            WTradeRespGetLong(ResponseID,i,W_MoneyType,&long_out);	        //�������� '0'-RMB '1'-HKD '2'-USD           
            WTradeRespGetStr(ResponseID,i,W_Remark,&p_out);	                //˵��                                     
            
            //Stock
            WTradeRespGetDouble(ResponseID,i,W_SecurityBalance,&double_out);//�ɷ����                                   
            WTradeRespGetDouble(ResponseID,i,W_SecurityAvail,&double_out);	//�ɷݿ���                                   
            WTradeRespGetDouble(ResponseID,i,W_SecurityForzen,&double_out);	//�ɷݶ���                                   
            WTradeRespGetDouble(ResponseID,i,W_TodayBuyVolume,&double_out);	//����������                                  
            WTradeRespGetDouble(ResponseID,i,W_TodaySellVolume,&double_out);//����������                                  
            WTradeRespGetDouble(ResponseID,i,W_SecurityVolume,&double_out);	//��ǰӵ����                                  
            WTradeRespGetDouble(ResponseID,i,W_CallVolume,&double_out);	    //����������                                  
            WTradeRespGetDouble(ResponseID,i,W_CostPrice,&double_out);	        //�ɱ��۸�                                   
            WTradeRespGetDouble(ResponseID,i,W_TradingCost,&double_out);		//��ǰ�ɱ�                                   
            
            WTradeRespGetDouble(ResponseID,i,W_LastPrice,&double_out);	        //���¼۸�                                   
            WTradeRespGetDouble(ResponseID,i,W_HoldingValue,&double_out);	//��ֵ                                     
            WTradeRespGetDouble(ResponseID,i,W_Profit,&double_out);	        //ӯ��                                     
            
            //Future
            WTradeRespGetLong(ResponseID,i,W_TradeSide,&long_out);
            WTradeRespGetLong(ResponseID,i,W_BeginVolume,&long_out);		//�ڳ�����                                   
            WTradeRespGetLong(ResponseID,i,W_EnableVolume,&long_out);		//��������                                   
            WTradeRespGetLong(ResponseID,i,W_TodayRealVolume,&long_out);	//���տ�ƽ������                                
            WTradeRespGetLong(ResponseID,i,W_TodayOpenVolume,&long_out);	//���տ��ֿ�������                               
            WTradeRespGetDouble(ResponseID,i,W_HoldingProfit,&double_out);	//����ӯ��                               
            WTradeRespGetDouble(ResponseID,i,W_TotalFloatProfit,&double_out);//�ֲָ���ӯ��  
            WTradeRespGetDouble(ResponseID,i,W_PreMargin,&double_out);	    //�Ͻ����ձ�֤�� 
            
        }


		WTradeBuffRelease(ResponseID);	//ʹ�ú��ͷŻر�����
    }
}    
 
void Test_OrderQry()
{
    long ResponseID = 0;
    {
        int RequestID = WTradeCreateReq();

        WTradeReqSetLong(RequestID,W_LogonID,LogonID);
        WTradeReqSetLong(RequestID,W_FuncID,WD_FUNCID_ORDER_QRY);      //���ܺ�        

        WTradeSendReqSync(RequestID,&ResponseID);
    }

    Test_OrderQry_report(ResponseID);
}

void Test_OrderQry_report(long ResponseID)
{
    long    MarketType=0;

    if(ResponseID)
    {
        WTradeRespGetLong(ResponseID,0,W_FuncID,&long_out);       
        WTradeRespGetLong(ResponseID,0,W_ErrID,&long_out);
        WTradeRespGetStr(ResponseID,0,W_ErrMsg,&p_out);

        long record_count = 0;
        WTradeRespGetLong(ResponseID,0,W_ResponseCount,&record_count);			//Ӧ��ļ�¼����       

        for( int i=0; i<record_count; ++i )
        {
            WTradeRespGetStr(ResponseID,i,W_Customer,&p_out);   	            //�ͻ���                                                                    
            WTradeRespGetStr(ResponseID,i,W_AssetAccount,&p_out);	            //�ʽ��˺�                                                                   
            WTradeRespGetStr(ResponseID,i,W_MoneyType,&p_out); 					//��������                                                                   
            WTradeRespGetLong(ResponseID,i,W_MarketType,&MarketType);	        //֤ȯ�г�                                                               
                                                                                                                                                             
            WTradeRespGetLong(ResponseID,i,W_TradeSide,&long_out);
            WTradeRespGetStr(ResponseID,i,W_ExtFlag1,&p_out);	                //��չ��־
            WTradeRespGetStr(ResponseID,i,W_ExtFlag2,&p_out);   	            //��չ��־                                                                   
            WTradeRespGetStr(ResponseID,i,W_ExtFlag3,&p_out);   	            //��չ��־                                                                   
            WTradeRespGetLong(ResponseID,i,W_OrderStatus,&long_out);	        //ί��״̬ '0'-���� '1'-���� '2'-��Ч                                              
            WTradeRespGetStr(ResponseID,i,W_Shareholder,&p_out);   				//�ɶ�����                                                                   
            WTradeRespGetStr(ResponseID,i,W_SecurityCode,&p_out);  				//֤ȯ����                                                                   
            WTradeRespGetStr(ResponseID,i,W_SecurityName,&p_out);  				//֤ȯ����                                                                   
            WTradeRespGetStr(ResponseID,i,W_DepartmentID,&p_out);      			//����Ӫҵ��                                                                  
            WTradeRespGetLong(ResponseID,i,W_OrderDate,&long_out);   	        //ί������                                                                   
            WTradeRespGetLong(ResponseID,i,W_OrderTime,&long_out);   	        //ί��ʱ��                                                                   
            WTradeRespGetLong(ResponseID,i,W_OrderVolume,&long_out); 	        //ί������                                                               
            WTradeRespGetDouble(ResponseID,i,W_OrderPrice,&double_out);  	    //ί�м۸�                                                                   
            WTradeRespGetLong(ResponseID,i,W_TradedVolume,&long_out);  			//�ɽ�����                                                               
            WTradeRespGetDouble(ResponseID,i,W_TradedPrice,&double_out);   		//�ɽ�����                                                                   
            WTradeRespGetLong(ResponseID,i,W_CancelVolume,&long_out);	        //��������                                                               
            WTradeRespGetDouble(ResponseID,i,W_LastPrice,&double_out);     	    //���¼۸�                                                                   
            WTradeRespGetStr(ResponseID,i,W_OrderNumber,&p_out); 	            //ί�����                                                                                                                                                                                              
                                                                                                                                                             
            WTradeRespGetDouble(ResponseID,i,W_PreMargin,&double_out);			//���ֶ��ᱣ֤��                                                                
            WTradeRespGetDouble(ResponseID,i,W_TotalFrozenCosts,&double_out);	//�����ܷ���                                                                  
            WTradeRespGetLong(ResponseID,i,W_HedgeType,&long_out);   	        //�ױ���־  '0'-Ͷ��  '1'-��ֵ                                                   
            WTradeRespGetStr(ResponseID,i,W_Seat,&p_out);      					//ϯλ��                                                                    
            WTradeRespGetStr(ResponseID,i,W_Agent,&p_out);      	            //�����̺�                                                                   
            WTradeRespGetStr(ResponseID,i,W_Remark1,&p_out);      				//˵��1                                                                    
            WTradeRespGetStr(ResponseID,i,W_Remark2,&p_out);      				//˵��2                                                                    
                       
        }


		WTradeBuffRelease(ResponseID);	//ʹ�ú��ͷŻر�����
    }
}

void Test_TradeQry()
{
    long ResponseID = 0;
    {
        int RequestID = WTradeCreateReq();

        WTradeReqSetLong(RequestID,W_LogonID,LogonID);
        WTradeReqSetLong(RequestID,W_FuncID,WD_FUNCID_TRADE_QRY);      //���ܺ�     

        WTradeSendReqSync(RequestID,&ResponseID);
    }

    Test_TradeQry_report(ResponseID);
}

void Test_TradeQry_report(long ResponseID)
{
    if(ResponseID)
    {
        WTradeRespGetLong(ResponseID,0,W_FuncID,&long_out);       
        WTradeRespGetLong(ResponseID,0,W_ErrID,&long_out);
        WTradeRespGetStr(ResponseID,0,W_ErrMsg,&p_out);

        long record_count = 0;
        WTradeRespGetLong(ResponseID,0,W_ResponseCount,&record_count);			//Ӧ��ļ�¼����   

        for( int i=0; i<record_count; ++i )
        {
            WTradeRespGetStr(ResponseID,i,W_Customer,&p_out);   	            //�ͻ���                                                              
            WTradeRespGetStr(ResponseID,i,W_AssetAccount,&p_out);	            //�ʽ��˺�                                                             
            WTradeRespGetStr(ResponseID,i,W_MoneyType,&p_out);  	            //��������                                                             
            WTradeRespGetStr(ResponseID,i,W_MarketType,&p_out); 	            //֤ȯ�г�                                                             
            WTradeRespGetLong(ResponseID,i,W_TradeSide,&long_out);
            WTradeRespGetStr(ResponseID,i,W_ExtFlag1,&p_out);   	            //��չ��־
            WTradeRespGetStr(ResponseID,i,W_ExtFlag2,&p_out);    	            //��չ��־                                                             
            WTradeRespGetStr(ResponseID,i,W_ExtFlag3,&p_out);    	            //��չ��־                                                             
            WTradeRespGetStr(ResponseID,i,W_TradedStatus,&p_out);  				//�ɽ�״̬ '0'-���� '1'-����                                               
            WTradeRespGetStr(ResponseID,i,W_Shareholder,&p_out);    	        //�ɶ�����                                                             
            WTradeRespGetStr(ResponseID,i,W_SecurityCode,&p_out);   	        //֤ȯ����                                                             
            WTradeRespGetStr(ResponseID,i,W_SecurityName,&p_out);   	        //֤ȯ����                                                             
            WTradeRespGetLong(ResponseID,i,W_OrderDate,&long_out);   	        //ί������                                                             
            WTradeRespGetLong(ResponseID,i,W_OrderTime,&long_out);   	        //ί��ʱ��                                                             
            WTradeRespGetLong(ResponseID,i,W_OrderVolume,&long_out); 	        //ί������                                                             
            WTradeRespGetDouble(ResponseID,i,W_OrderPrice,&double_out);  	    //ί�м۸�                                                             
            WTradeRespGetLong(ResponseID,i,W_TradedVolume,&long_out);  			//�ɽ�����                                                             
            WTradeRespGetDouble(ResponseID,i,W_TradedPrice,&double_out);   		//�ɽ��۸�                                                             
            WTradeRespGetLong(ResponseID,i,W_CancelVolume,&long_out);	        //��������                                                             
            WTradeRespGetLong(ResponseID,i,W_TradedDate,&long_out);    			//�ɽ�����                                                             
            WTradeRespGetLong(ResponseID,i,W_TradedTime,&long_out);    			//�ɽ�ʱ��                                                             
            WTradeRespGetDouble(ResponseID,i,W_LastPrice,&double_out);    		//���¼۸�                                                             
            WTradeRespGetStr(ResponseID,i,W_OrderNumber,&p_out); 	            //ί�����                                                             
            WTradeRespGetStr(ResponseID,i,W_TradedNumber,&p_out);  				//�ɽ����                                                             
            WTradeRespGetStr(ResponseID,i,W_Remark,&p_out);      	            //˵��                                                               
            WTradeRespGetStr(ResponseID,i,W_Remark1,&p_out);     	            //����˵��                                                             
            WTradeRespGetDouble(ResponseID,i,W_MadeAmt,&double_out);	        //�ɽ����                                                             

            
            WTradeRespGetLong(ResponseID,i,W_AmountPerHand,&long_out);    		//ÿ�ֶ���                                       
            WTradeRespGetLong(ResponseID,i,W_HedgeType,&long_out);    			//�ױ���־  '0'-Ͷ��  '1'-��ֵ                       
            WTradeRespGetDouble(ResponseID,i,W_TotalFrozenCosts,&double_out);	//�����ܷ���                                      
            WTradeRespGetDouble(ResponseID,i,W_DropProfit,&double_out);			//ƽ��ӯ��                                       
            WTradeRespGetDouble(ResponseID,i,W_DropFloatFrofit,&double_out);	//ƽ�ָ���ӯ��	                                 
            WTradeRespGetStr(ResponseID,i,W_Seat,&p_out);     					//ϯλ��                                        
            WTradeRespGetStr(ResponseID,i,W_Agent,&p_out);     					//�����̺�                                       
            
        }


		WTradeBuffRelease(ResponseID);	//ʹ�ú��ͷŻر�����

    }
}

void Test_DepartmentQry()
{
    long ResponseID = 0;
    {
        int RequestID = WTradeCreateReq();

        WTradeReqSetStr(RequestID,W_BrokerID,"��ȯ��BrokerID");         //ȯ�̴���  
        WTradeReqSetLong(RequestID,W_FuncID,WD_FUNCID_DEPARTMENT_QRY);	//���ܺ�  

        WTradeSendReqSync(RequestID,&ResponseID);
    }

    Test_DepartmentQry_report(ResponseID);
}

void Test_DepartmentQry_report(long ResponseID)
{
    if(ResponseID)
    {
        WTradeRespGetLong(ResponseID,0,W_FuncID,&long_out);       
        WTradeRespGetLong(ResponseID,0,W_ErrID,&long_out);
        WTradeRespGetStr(ResponseID,0,W_ErrMsg,&p_out);

        long record_count = 0;
        WTradeRespGetLong(ResponseID,0,W_ResponseCount,&record_count);		//Ӧ��ļ�¼���� 
    
        for( int i=0; i<record_count; ++i )
        {
            WTradeRespGetStr(ResponseID,i,W_DepartmentID,&p_out);          	//Ӫҵ��ID                                                              
            WTradeRespGetStr(ResponseID,i,W_DepartmentName,&p_out);        	//Ӫҵ������                                                              
            WTradeRespGetStr(ResponseID,i,W_AvailMarketFlag,&p_out);		//�ɲ����г���ʶ, ��λ����                                                      
        }


		WTradeBuffRelease(ResponseID);	//ʹ�ú��ͷŻر�����
    }
}

void Test_AccountQry()
{
    long ResponseID = 0;
    {
        int RequestID = WTradeCreateReq();

        WTradeReqSetLong(RequestID,W_LogonID,LogonID);
        WTradeReqSetLong(RequestID,W_FuncID,WD_FUNCID_ACCOUNT_QRY);      //���ܺ�    

        WTradeSendReqSync(RequestID,&ResponseID);
    }

    Test_AccountQry_report(ResponseID);
}

void Test_AccountQry_report(long ResponseID)
{
    if(ResponseID)
    {
        WTradeRespGetLong(ResponseID,0,W_FuncID,&long_out);       
        WTradeRespGetLong(ResponseID,0,W_ErrID,&long_out);
        WTradeRespGetStr(ResponseID,0,W_ErrMsg,&p_out);

        long record_count = 0;
        WTradeRespGetLong(ResponseID,0,W_ResponseCount,&record_count);		//Ӧ��ļ�¼����  
    
        for( int i=0; i<record_count; ++i )
        {
            WTradeRespGetLong(ResponseID,i,W_ShareholderStatus,&long_out);	//״̬  '0'-���� '1'-����        
            WTradeRespGetStr(ResponseID,i,W_MainShareholderFlag,&p_out);	//���ɶ���־ '1'-��  '0'-��           
            WTradeRespGetStr(ResponseID,i,W_AccountType,&p_out);	        //�˺�����                         
            WTradeRespGetStr(ResponseID,i,W_MarketType,&p_out); 	        //�г�����                         
            WTradeRespGetStr(ResponseID,i,W_DepartmentID,&p_out);      		//����Ӫҵ��                        
            WTradeRespGetStr(ResponseID,i,W_Shareholder,&p_out);   			//�ɶ�����                         
            WTradeRespGetStr(ResponseID,i,W_CustomerName,&p_out);   	    //�ͻ�����                         
            WTradeRespGetStr(ResponseID,i,W_AssetAccount,&p_out);	        //�ʽ��˺�                         
            WTradeRespGetStr(ResponseID,i,W_Customer,&p_out);   	        //�ͻ���                          
            WTradeRespGetStr(ResponseID,i,W_Seat,&p_out);	                //ϯλ��                          
        }


		WTradeBuffRelease(ResponseID);	//ʹ�ú��ͷŻر�����
    }
}
    
void Test_ReckoningQry()
{
    long ResponseID = 0;
    int RequestID = WTradeCreateReq();

    WTradeReqSetLong(RequestID,W_LogonID,LogonID);
    WTradeReqSetLong(RequestID,W_FuncID,WD_FUNCID_RECKONING_QRY);      //���ܺ�    

    WTradeSendReqSync(RequestID,&ResponseID);

    Test_ReckoningQry_report(ResponseID);
}

void Test_ReckoningQry_report(long ResponseID)
{
    if(ResponseID)
    {
        WTradeRespGetLong(ResponseID,0,W_FuncID,&long_out);      
        WTradeRespGetLong(ResponseID,0,W_ErrID,&long_out);
        WTradeRespGetStr(ResponseID,0,W_ErrMsg,&p_out);

        long record_count = 0;
        WTradeRespGetLong(ResponseID,0,W_ResponseCount,&record_count);        //Ӧ��ļ�¼����  
    
        for( int i=0; i<record_count; ++i )
        {
            WTradeRespGetStr(ResponseID,i,W_Customer,&p_out);		//�ͻ���
	        WTradeRespGetStr(ResponseID,i,W_AssetAccount,&p_out);	//�ʽ��˺�
	        WTradeRespGetLong(ResponseID,i,W_InfoDate,&long_out);	//��Ϣ����
	        WTradeRespGetLong(ResponseID,i,W_InfoTime,&long_out);	//��Ϣʱ��
	        WTradeRespGetStr(ResponseID,i,W_InfoMsg,&p_out);	    //��Ϣ����
        }


		WTradeBuffRelease(ResponseID);	//ʹ�ú��ͷŻر�����
    }
}


