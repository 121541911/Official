% ����:����2013��9��16�չɼ���200�վ����Ϸ��Ĺ�Ʊ���뼰���ơ�
% ��һ��  ������ 2013��7��29��
clear
w=windmatlab;
w_wset_data=w.wset('SectorConstituent','date=20130728;sector=CSI���ڵز�');
%% ��ȡ��Ʊ���̼���200�վ��ߣ�MA_N=200���۸�
Data1=w.wss(w_wset_data(:,2),'close;MA','tradeDate=20130916','MA_N=200','priceAdj=F','cycle=D');
N=Data1(:,1)>Data1(:,2);
%% �ɼ�������200�վ����Ϸ��Ĺ�Ʊ
List=w_wset_data(N,2:3);
%% �ɼ�������200���·��Ĺ�Ʊ
h1=figure('Position', [500 400 422 550],'Name','�ɼ���200�վ����Ϸ���Ʊ');
uitable('Parent',h1,'Data',List,'fontsize',15,  'Position', [25 40 420 500],'ColumnWidth',{180 190 });





