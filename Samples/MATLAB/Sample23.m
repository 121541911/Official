%   ����:���Ծ���MA�������档
% 1��������ѡʱ������е�a�ɣ�������ù�5�վ����ϴ�30�վ���ʱ�����롣
% 2�����е���ʱ����ڵ��ƹɼ�10�վ���ʱ������
% 3������ֹʱ���ĩβ����û�е���10�վ��ߣ���������̼ۼ��������ʡ�
% 4��ͳ�Ƹ�ʱ�����ÿ���������
% ��һ��  ������ 2013��7��29��
% 
clear
w=windmatlab;
[w_wset_data,w_wset_codes,w_wset_fields,w_wset_times,w_wset_errorid,w_wset_reqid]=w.wset('SectorConstituent','date=20130728;sector=CSI���ڵز�');
[m,n]=size(w_wset_data);
for i=1:60
data   = w.wsd(w_wset_data{i,2},'close',today-100,today);
[MA5]  = w.wsd(w_wset_data{i,2},'EXPMA',today-100,today,'EXPMA_N=5','Fill=Previous');
[MA10] = w.wsd(w_wset_data{i,2},'EXPMA',today-100,today,'EXPMA_N=10','Fill=Previous');
[MA30] = w.wsd(w_wset_data{i,2},'EXPMA',today-100,today,'EXPMA_N=30','Fill=Previous');
%%  ����
open=0;
for j=1:length(data)
   if MA5(j)>=MA30(j) && open==0
   open=data(j);
   ret(j)=0;
   elseif  data(j)<MA10(j) && open>0
   ret(j)= log(data(j)/open);
   open=0;
   else
   ret(j)=0; 
   end    
end
if open>0;ret(end)= log(data(end)/open);end
blotReturn(:,i)=ret(:);
end
sumReturn=cumsum(blotReturn);
Data{1,1}='��������';
Data{1,2}='ƽ������';
Data{2,1}='���߲���';
Data{2,2}=num2str(nanmean(sumReturn(end,:)));
Data{3,1}='��Ʊ����';
Data{3,2}='��������';
Data=[Data;[w_wset_data(1:60,3),mat2cell(sumReturn(end,:)',ones(60,1),1)]];
h1=figure('Position', [500 300 305 455],'Name','���߲���ͳ��');
uitable('Parent',h1,'Data',Data,'fontsize',15,  'Position', [10 10 300 450],'ColumnWidth',{110 150 });


