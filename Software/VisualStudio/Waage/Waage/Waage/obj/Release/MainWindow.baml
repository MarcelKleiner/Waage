   M S B A M L   `   `   `  ���� @  <Waage, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullclr-namespace:WaageWaage      Waage.MainWindow   R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     @d2http://schemas.microsoft.com/expression/blend/2008     Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     %localclr-namespace:Waage     H DMahApps.Metro, Version=1.6.5.1, Culture=neutral, PublicKeyToken=null6mah,http://metro.mahapps.com/winfx/xaml/controls    � Title$  
MainWindow��$��364.667��$	��837��.���  � ColumnDefinitions �� $	��204 ��� .+��  �� ��  � RowDefinitions �� $��35 ��� $��30 ��� $��40 ��� �� $��33 �.+��� 
���   �$��1q�$��Right=�$	��0,3q�$��1��$��5��$��1���� -    ��Name$ label��$��COM Settings��$��0q�$��Center=�$��Center=�$��2���� -    ��Name$ cbCOM��$��Center=�$��20��$
��60,5q�$��1��$��Center=�$��84��$��2���� -    ��Name$ 
cmdConnect��$��Connect��$��Center=�$��26��$
��16,7q�$��2��$��Center=�$��70���� -   $ cmdDisconnect��$��
Disconnect��$��Center=�$��26��$
��16,7q�$��2��$��Center=�$��70��$��1���� -   $ 
cmdRefresh��$��1��$
��Left=�$��19��$��51,6,0,0q�$��1��$	��Top=�$��22��.���� -    ��Name$ image��$��Img/Refresh_32px.png���� $��Status:��$
��Left=�$��4��$��47��$��Center=��� -   $ 	lblStatus��$��Disconnected��$��Right=�$��4��$	��167��$��Center=�$��2��� $��1��$��0q� �� �� $��40 ��� $��50 �.+�� $��0q�$��2�� �� $
��109* ��� $
��109* ��� $
��107* ��� $	��50* ��� $
��108* �.+��� -   $ 
cmdReadLog��$��	Log lesen��$��Center=�$��25��$��0q�$��Center=�$��95���� -	   $ cmdClearLog��$��Center=�$��25��$��0q�$��Center=�$��95��$��2��$��Log löschen���� -
   $ 	cmdExport��$��Export��$��Center=�$��26��$��0q�$��Center=�$��95��$��4���� -   $ cmdClearEntries��$��Einträge löschen��$��Center=�$��26��$��Center=�$��95��$��1��$��0q��� 
���   �$��1q�$��1��$
��15,0q�$��Bottom=�$��1��-  'MahApps.Metro.Controls.MetroProgressBar  -     Name$ 
pbProgress��$��5q�$��1�����	#FF0AD301�� -    ��Name$ listView��$��5q�	 �� View	 �� .P��� 
 �� Width$	
 120��-   
nDatum��$��Datum�� �� DisplayMemberBinding �� *datum+�� $	
 100��-   	nZeit��$
��Zeit�� �� *zeit+�� $	
 100��-   nGewicht��$��Gewicht�� �� *	gewicht+�� $	
 100��-   
nPreis��$��Preis�� �� *preis+�� $	
 150��-   	nWachstyp��$��Wachstyp�� �� *
wachstyp+