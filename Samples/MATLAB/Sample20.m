function varargout = Sample20(varargin)
%{
���ܣ���Խ���GUI��
�汾��ʷ��
�����£�2013��07��05�գ���Խ��׻���ģ��
�����£�2013��08��05�գ��޸���ģ�岼�ã�����������˳ֲּ��ֲ�ӯ���� 
�ο����ף�
�����£������ڹ������ʲ��������������պ����ѧ�����磬2008��
Ernest P. Chan (2009). Quantitative Trading: How to Build Your Own Algorithmic Trading Business. John Wiley & Sons

%% ��Խ��׸��
��Խ�����ͳ��������һ����ʽ������ͨ���Թ�Ʊ��ʷ�۸����Ƶ�ͳ�Ʒ�����ѡ�������Ƽ۸����ƵĹ�Ʊ�ԣ������߼۸����Ƴ������Է���ʱ��
������Լ۸�����ƫ�ߵĹ�Ʊ��������Լ۸�����ƫ�͵Ĺ�Ʊ������һ����ϣ����۸����ƻع鵽����ˮƽʱ����ƽ�ֲ����������۲����档
�ò�������Ŀ��Ϊ����������г����Բ��ԡ�

%% ��ѡ��Ʊ��ѡ���׼��
����������Ҫ����ͬһ���ڵĹ�Ʊ����Ӧ���й�˾ҵ����ͬ���ɱ���ǿ����Ҫע����ǣ���ҵ���ֵ�Խϸ��ͬ��ҵ�ڹ�˾�ġ����ƶȡ����ܻ�Խ�ߣ�
����Ӧ����ҵ�ڸ�����Ŀ����٣���ɸѡ���Ĺ�Ʊ����ĿҲ��Խ�٣������ҵ������Ҫ����һ���ĳ߶ȡ�
�����б�ѡ��Ʊ8�����������£�
000001.SZ   ƽ������
002142.SZ   ��������
600000.SH   �ַ�����
600015.SH   ��������
600036.SH   ��������
601009.SH   �Ͼ�����
601166.SH   ��ҵ����
601169.SH   ��������

%% ��Է��������֣�
����1�����ϵ����
    ���ϵ�����������ʵ����ϵ�����������Ʒ�������������ϵ������0.8�ù�Ʊ����ѡ��
����2���۸���ʷ�
    ���ȼ���2��Ʒ��ʱ�����еļ۸�֮�ȣ�������ʷ�۸�Ȳ������ȷ���������䣬
����3����λ����
    ��λ���������£����ǹ�Ʊ�۲��Ƿ���ڵ�λ����
����4�����ѡ��
    �����ɹ�Ʊ�ԡ�
����5������������
    ���öԹɼ۽�����ϣ�������ϲ��ж������ԡ�
%%  ��Է��տ���
1.  ������С
    ��Ҫ�Ż������ɲ���������ʹ���㹻��Ļز����ݣ��ǽ�������Ǩ��ƫ���������������ݾ������ÿ�����ɲ���Ҫ��252�����ݵ㣨�г�һ��Ľ����������Ż���
    ��һ���������ĵ��ս���ģ�ͻز⣬����Ҫ��������ռ۸����ݡ�����Ƿ��ӽ���ģ�ͣ���������Ҫ�߸��£�252/390�꣩�ķ������ݣ�ÿ�콻�׷�����6.5*60=390����
    Ҫע����ǣ��߸��µķ������ݣ���һ���ս���ģ����˵��ԶԶ�����ģ���Ϊ��ʱʵ����ֻ��7*21=147����Ч���ݣ�ÿ�½�������21����
2.  ���������
    ����ʷ���ݷ�Ϊǰ�����Σ��ú�һ�ζԲ��Խ��������������Out-of-Sample Testing����
    ģ�Ͳ������Ż���ǰһ�����ݣ���Ϊѵ����[training set]����ģ��Ч���ļ����ú�һ�����ݣ���Ϊ������[test set]����
    ��������������Ҫ������£����������������ò���������֮һ����������������ѵ�����Ĵ�С��ǰ���ᵽ�ľ������������������������£�����ѵ���������Ų��������߶��ڲ�����Ҳ�����ŵġ�
    ����ʵ���Ϻ���������һ�㣬���������ϵļ�Ч����Ҫ˵�ù�ȥ������ģ�;ʹ�������Ǩ��ƫ���Ҫ��һ���򻯲����ٲ�����
    ��̬�����Ż���moving optimization���Ǹ����ܵġ�ȴ����ʱ�����������������ͨ��ʹ����������Ӧ�仯����ʷ���ݣ�����������Ǩ��ƫ�
    ��ཻ��Ա��֪����������δ��������ʵ���ݵķ��潻�ף�paper trading������׵����������������ͨ�����潻�׳������ҳ��ȿ�ƫ��ҷ��ָ����������ص����⣨�������£���
    ����һ����Ҫ�ûز�����ʵ�����Ĺ������ԣ��Ӳ��Գ����յ������յ����ʱ���ǲ��۲��۵�����������ڡ�ֻҪ��ʹ�����ʱ����������Ż����������ʱ�������ͬ���������������潻�ס�
3.  �����Է��� 
    ��ģ�Ͳ����Ż���ͨ���������ļ���֮�󣬸ı���Щ������ı�ģ�͵Ķ��Ծ��ߣ����۲�ģ�ͼ�Ч��ѵ�����Ͳ������ϵı仯�������Ч�仯�ܴ��ڲ���ȡ�κ�����ֵʱ��Ч�����㣬ģ�ͺܿ��ܾ�������Ǩ��ƫ�
    ���ּ�ģ�͵ķ�����ֵ��һ�ԡ������Ƿ��������Ҫ�����ͬ��������һ��һ�����Ƴ���Щ������ģ����ѵ�����ϵļ�Ч��ʱ�ή��̫���أ�ģ���ڲ������ϵļ�Ч����Ӧ�Ľ�����ֻҪû���������Ͳ������ϵļ�Ч����Ӧ�þ������Ƴ������������Լ���Ͳ�����
�ڼ��˲���������������ȷ������������ļ�Ч�ڲ�����������΢С�仯�²���������Ӱ��֮�󣬿��ǽ��ʽ���䵽��ͬ�Ĳ���ֵ���������������ʽ��ڲ����ϵ�ƽ��������һ��ȷ��ģ����ʵ�Ľ��׼�Ч��ز⼨Ч����
 
%% ��������  
����ʷ���ݶԲ��Եļ�Ч������ʵ��ģ�����Ĺ��̽лز⣬��ǣ��������ϸ�����⣺ 
��        ���ݣ�  ��Ʊ��ֺͺ�������������߼ۡ���ͼ۵�����������ѡ��ƫ��
��        ��Ч������ �껯���ձȺ������
��        �ȿ�ƫ� �ڹ�ȥ�Ľ��׾�����ʹ���޷��õ����º���Ϣ
��        ����Ǩ��ƫ� �����ʷ����ʱʹ�ù���������ô��������ݡ�����������������Է������������ƫ��
��        ���׳ɱ��� ���׳ɱ�����Ӱ����Լ�Ч
��        ���ԸĽ��� ͨ��΢С�������Ż���Ч�ĳ�������
%% ��Խ�������
1.  ��Խ����ںܴ�����Ϲ�ܵ����г����գ��нϸߵİ�ȫ�߼�
    ��Խ�����һ���г����Բ��ԣ�ͨ��ͬʱ����һ֧��Ʊ����һ֧��Ʊ������ϵͳ���ձ�¶Ϊ�����ϣ���׽�����������ڼ۸��ֲ���ֲ����Ĳ��졣
ͬʱ����Խ��׵Ŀ�ͷ���ֱ���ͱȵ����ͷ�����������и��п��ܻ�ø��ߵİ�ȫ�߼ʣ���Ϊ�µ��Ĺ�Ʊ������ǵģ����������Ƿ���
2.  ���г���Χ�����ʵ�����£�������Ա��صĲ�����Ϊ����
    ͨ�������л��������У�Ͷ����ͨ��Ѱ���������Ǵ����߻ر������ѶȺܴ��Բ�ע������ױ����Ρ��������г������£�Ͷ������Ҫ׷�����ر���
    �Ͳ�����ȫ������������Ʒ����ҪתͶ���������Ʒ��ͬʱ�����л��������У����ɵķ�ϵͳ�Է��ջ��ݻ�Ϊϵͳ�Է��գ������ͷ�����߷ǳ����У�
    �г��ϵ�������Ϣ���п��ܱ��Ŵ����ɸ����µ�����ʹͶ�����Ѿ��ڸ����ϻ�ȡ�������棬Ҳ���п�����Ϊ����ԭ�������汻Ĩƽ��
    Ŀǰ���г����ܸ�������Ӱ�죬�ʽ�����ֹ���̬�ȣ���ʹ���г�������ģ�Ҳ����΢�������˽��볡��
    ����˵Ŀǰ��A���г���Χ�������ʣ��������Ļ����£���׷��߶����棬ѡȡ������Կɿأ���������Ƚ��Ĳ������ԣ����Ǳ�ס�ʱ���
    ���ʲ�����ֵ������֮�٣�ֻ�������������鵽����ʱ�򣬲������㹻���ʱ�����Ͷ�룬��������Ϊ���ֻ������ζ����и�̾��
3.  ��Ŀǰ����Ͷ���߲��ܽ���A���г�ֱ�����յ�ǰ���£���Խ��׵Ļ����ʤ��ϸ�
    �κ��������ᣬ���ǲ������Խ�࣬����Խ�٣�ETF������ˣ���ָ�ڻ�������ˣ�ͳ������Ҳ����ˡ�Խ��רҵ��Ͷ���ߣ�
    Խ�ܹ�׼ȷ��׼�ذ��ջ��ᣬ���������Խ�࣬�����Խ�ѱ����֡�Ŀǰ���ҹ�A��������ȯҵ�񻹴��ڷ�չ�ڣ�����Ͷ���߻�����ֱ�ӽ���A�����ղ�����
    ������ͨ��Ͷ�������������ڽ�����Խ��ף���������õ�ʱ����
%% ��Խ��׷���
    �Խ��׵ķ�����Դ���������֣�Ͷ���߲������г�ͻ���¼���ģ�ͱ�����
������ͳ��������ͻ�����г��¼��п��ܶԸ���̬�����Ӱ�죬���ģ��ʧЧ��ͬʱ����Խ��ױ���Ҳ�����޷���������������һ��ʤ�ʵ��������ԡ�
�ӵ�һ�쿪ʼ����Խ��׿�ʼ�Ҿ�֪���ҵ�����п϶����г��ֿ������ϣ�����Ҫ���ģ����������Լ���רҵ֪ʶ�����ϵ�ȥ���ƺ͵���ģ�ͣ�
ʹ��������г������ٿ���ķ��������Ǵӳ��ںʹ�������������Խ����Ƿ��տɿ������Ƚ��Ĳ��ԡ�
%%   ����ͳ��
�����󣺼����λز������ÿ���ʲ����������ۼ�
����ʧ�������λز������ÿ���ʲ�������ʧ�ۼ�
�����󣺸ò��Ա��λز�ʱ����ｻ�ײ��������е����棨���������ѣ����������������ʧ֮��
�������ѣ������ײ����������ѡ����������ǰ�����ǵ��쿪ƽ�Ļ���ֻ��һ��������
 
�ܽ��״�������¼���׵Ĵ�������һ�Կ��ֺ�ƽ����һ�ν���
ӯ����������ʾ�������
ӯ��������������ӯ������
����ʧ����������ʾ��ʧ�Ĵ���
  
���ӯ��:������ӯ����ӯ�������Ǳ�����Ľ��
�����ʧ:
��������ʧ����ʧ�����Ǳʽ��׵ľ�����ʧ���
ƽ��ӯ��:�������ƽ��ֵ
ƽ����ʧ:����ʧ��ƽ��ֵ
ƽ��ӯ��/ƽ����ʧ:��ƽ��ӯ����ƽ����ʧ�ı���
ƽ��������:�������ƽ��ֵ 
 
�������ӯ������:��¼����ӯ����������
���������ʧ����:��¼���������������
ӯ�����ӣ���ӯ��/����ʧ��:��������������ʧ�ı�ֵ
����Լ�ֲ���:��ʾ���ĳֲ���
��Ҫ�ʽ�:�����гֲ���Ҫ���ʽ�
�ʽ�ر��ʣ�������/��Ҫ�ʽ�
�����������Ҫ�ʽ�ı�ֵ
���س�:�����׻������������ 
%}


% SAMPLE20 MATLAB code for Sample20.fig
%      SAMPLE20, by itself, creates a new SAMPLE20 or raises the existing
%      singleton*.
%
%      H = SAMPLE20 returns the handle to a new SAMPLE20 or the handle to
%      the existing singleton*.
%
%      SAMPLE20('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in SAMPLE20.M with the given input arguments.
%
%      SAMPLE20('Property','Value',...) creates a new SAMPLE20 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before Sample20_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to Sample20_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help Sample20

% Last Modified by GUIDE v2.5 04-Sep-2013 16:42:39

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Sample20_OpeningFcn, ...
                   'gui_OutputFcn',  @Sample20_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before Sample20 is made visible.
function Sample20_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to Sample20 (see VARARGIN)

% Choose default command line output for Sample20
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes Sample20 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = Sample20_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
%%  ģ������ѡ��
v(1)=get(handles.radiobutton1,'value');
v(2)=get(handles.radiobutton2,'value');
v(3)=get(handles.radiobutton3,'value');
v(4)=get(handles.radiobutton4,'value');
v(5)=get(handles.radiobutton5,'value');
v1=find(v==1);
%%  ģ������ѡ��
va(1)=get(handles.radiobutton6,'value');
va(2)=get(handles.radiobutton7,'value');
v2=find(va==1);

%% ��ȡ��Ʊ��ʷ�۸�
set(handles.listbox1,'string',{1});
w=windmatlab;
%% 1.1 ���й�����
strStockList='000001.SZ,002142.SZ,600000.SH,600015.SH,600036.SH,601009.SH,601166.SH,601169.SH';
data=w.wss(strStockList,'sec_name,trade_code');
StockList=regexp(strStockList,'[,]','split');
StockList=StockList(:);
%% 1.2 ȡ����ʷ�۸�
price=[];
[~,~,~,numDate]=w.wsd(StockList{1},'close',today-200,today);
for i=1:length(StockList)
data1=w.wsd(StockList{i},'close',today-200,today,'Fill=Previous') ;
% ���̼�
open1=w.wsd(StockList{i},'open',today,today) ;
if iscell(open1)==1
openPrice(i)=NaN;
else
openPrice(i)=open1  ;  
end
%% �������Ӵ�����ʾ
if iscell(data1)==1;errordlg(['�������Ӵ���',data1{1}],'����������ϵ��');error;end
price=[price,data1];
end
w.close;
%% 1.3 ѡ�����ϵ���ߵĹ�Ʊ��
%% 1.3.1 ���ϵ����
[numDays,numAssets]=size(price);
ret=price2ret(price);
matCorrcoef=corrcoef(ret);
t=1;
switch v1
    case 1
for i=2:8
    for j=1:i-1
        if matCorrcoef(i,j)>0.8;
        pairs(t,1:3)=[t,i,j]  ;
        cellPairs(t,1)={[data{i,1},' VS ',data{j,1}]};
        cellPairs(t,2)=data(i,1);
        cellPairs(t,3)=data(j,1);   
        cellPairs{t,4}=i;    
        cellPairs{t,5}=j;    
        t=t+1;
        end
    end
end
%% 1.3.2 �۸���ʷ�
    case 2
t=1;
for i=2:8
  for  j=1:i-1
    ret1=price(:,i)/mean(price(:,i));
    ret2=price(:,j)/mean(price(:,j));
    ret=ret1./ret2;
    if std(ret)<0.1
        pairs(t,1:3)=[t,i,j]  ;
        cellPairs(t,1)={[data{i,1},' VS ',data{j,1}]};
        cellPairs(t,2)=data(i,1);
        cellPairs(t,3)=data(j,1);   
        cellPairs{t,4}=i;    
        cellPairs{t,5}=j;    
        t=t+1;             
    end   
  end
end
%% 1.3.3 ��λ����
    case 3
t=1;
for i=2:8
  for  j=1:i-1
    parReg=regress(price(:,i),[ones(numDays,1),price(:,j)]);
    dis=price(:,i)-parReg(1)-parReg(2)*price(:,j);
    h = adftest(dis,'alpha',0.02)   ; 
    if h==1
        pairs(t,1:3)=[t,i,j]  ;
        cellPairs(t,1)={[data{i,1},' VS ',data{j,1}]};
        cellPairs(t,2)=data(i,1);
        cellPairs(t,3)=data(j,1);   
        cellPairs{t,4}=i;    
        cellPairs{t,5}=j;    
        t=t+1;             
    end   
  end
end
%% 1.3.4 �����Է�
    case 4
rand('seed',1);
clear cellPairs;
t=1;
for i=2:8
  for  j=1:i-1
    if rand<0.5
        pairs(t,1:3)=[t,i,j]  ;
        cellPairs(t,1)={[data{i,1},' VS ',data{j,1}]};
        cellPairs(t,2)=data(i,1);
        cellPairs(t,3)=data(j,1);   
        cellPairs{t,4}=i;    
        cellPairs{t,5}=j;    
        t=t+1;             
    end   
  end
end
%% 1.3.5 ��̬���
    case 5
clear cellPairs
t=1;
for i=2:8
  for  j=1:i-1
    parReg=regress(price(:,i),[ones(numDays,1),price(:,j)]);
    dis=price(:,i)-parReg(1)-parReg(2)*price(:,j);
    dis=abs(dis);
    if max(dis)<3
        pairs(t,1:3)=[t,i,j]  ;
        cellPairs(t,1)={[data{i,1},' VS ',data{j,1}]};
        cellPairs(t,2)=data(i,1);
        cellPairs(t,3)=data(j,1);   
        cellPairs{t,4}=i;    
        cellPairs{t,5}=j;    
        t=t+1;             
    end   
  end
end
end 

%% ����۲��
switch v2
    case 1
      matPrice=price./price(ones(size(price,1),1),:);
    case 2
      matPrice=price./repmat(nanmean(price),numDays,1);      
end
%% 1.4����۲�
for i=1:length(cellPairs)
priceSpread{i}=[numDate,matPrice(:,pairs(i,2))-matPrice(:,pairs(i,3))];      
end
%% 1.5 ����������Ϊ�ṹ����
BankData.cellPairs=cellPairs;      % ����۲������Ĺ�Ʊ��
BankData.StockList=StockList;      % ��Ʊ�б�
BankData.Price=price;              % ��Ʊ�۸�
BankData.matPrice=matPrice;        % ��һ���ļ۸�
BankData.numDate=numDate;          % ��������
BankData.priceSpread=priceSpread;  % �۲�
BankData.openPrice=openPrice;      % ���̼�
BankData.strStockList=strStockList;% ���йɹ�Ʊ�б�
set(handles.listbox1,'string',cellPairs(:,1)) ;


% --- Executes on selection change in listbox1.
function listbox1_Callback(hObject, eventdata, handles)
% hObject    handle to listbox1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns listbox1 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from listbox1


% --- Executes during object creation, after setting all properties.
function listbox1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to listbox1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in radiobutton6.
function radiobutton6_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton6
set(handles.radiobutton6,'value',1);
set(handles.radiobutton7,'value',0);

% --- Executes on button press in radiobutton7.
function radiobutton7_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton7
set(handles.radiobutton6,'value',0)
set(handles.radiobutton7,'value',1)
% --- Executes on button press in radiobutton1.
function radiobutton1_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton1
%% 2���۸����
set(handles.radiobutton1,'value',1);
set(handles.radiobutton2,'value',0);
set(handles.radiobutton3,'value',0);
set(handles.radiobutton4,'value',0);
set(handles.radiobutton5,'value',0);
% --- Executes on button press in radiobutton2.
function radiobutton2_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton2
%% 3����λ��
set(handles.radiobutton1,'value',0);
set(handles.radiobutton2,'value',1);
set(handles.radiobutton3,'value',0);
set(handles.radiobutton4,'value',0);
set(handles.radiobutton5,'value',0);




% --- Executes on button press in radiobutton3.
function radiobutton3_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton3
%% 1�����ϵ��
set(handles.radiobutton1,'value',0);
set(handles.radiobutton2,'value',0);
set(handles.radiobutton3,'value',1);
set(handles.radiobutton4,'value',0);
set(handles.radiobutton5,'value',0);
% --- Executes on button press in radiobutton4.
function radiobutton4_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton4
%% 5.��̬���
set(handles.radiobutton1,'value',0);
set(handles.radiobutton2,'value',0);
set(handles.radiobutton3,'value',0);
set(handles.radiobutton4,'value',1);
set(handles.radiobutton5,'value',0);
% --- Executes on button press in radiobutton5.
function radiobutton5_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton5
%% 4.������
set(handles.radiobutton1,'value',0);
set(handles.radiobutton2,'value',0);
set(handles.radiobutton3,'value',0);
set(handles.radiobutton4,'value',0);
set(handles.radiobutton5,'value',1);


% --- Executes during object creation, after setting all properties.
function radiobutton3_CreateFcn(hObject, eventdata, handles)
% hObject    handle to radiobutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
% set(handles.radiobutton1,'value',1)
% 

