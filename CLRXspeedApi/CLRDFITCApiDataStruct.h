#pragma once
#include <stdio.h>
#include <math.h>
#include "DFITCApistruct.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace CLRXspeedApi
{
	////////////////////////////////////////////////////////////
	///DFITCInstrumentTypeType:��Լ������������
	////////////////////////////////////////////////////////////
	public enum class CLRDFITCInstrumentType
	{
		COMM_TYPE = 0,														//�ڻ���Լ
		OPT_TYPE = 1														//��Ȩ��Լ
	};

	////////////////////////////////////////////////////////////
	///DFITCOrderAnswerStatusType:ί�лر�״̬����
	////////////////////////////////////////////////////////////
	public enum class CLRDFITCOrderAnswerStatusType :short
	{
		SPD_CANCELED = 1,													///ȫ������
		SPD_FILLED = 2,														///ȫ���ɽ�
		SPD_IN_QUEUE = 3,													///δ�ɽ����ڶ�����
		SPD_PARTIAL = 4,													///���ֳɽ����ڶ�����
		SPD_PARTIAL_CANCELED = 5,											///���ֳ���
		SPD_IN_CANCELING = 6,												///������
		SPD_ERROR = 7,														///����(�ϵ�����)
		SPD_PLACED = 8,														///δ�ɽ����ڶ�����it
		SPD_TRIGGERED = 10													///��̨�ѽ��գ�����δ��������
	};

	////////////////////////////////////////////////////////////
	///DFITCSpeculatorType:Ͷ������
	////////////////////////////////////////////////////////////
	public enum class CLRDFITCSpeculatorType
	{
		///Ͷ��
		SPD_SPECULATOR = 0,
		///�ױ�
		SPD_HEDGE = 1,
		///����
		SPD_ARBITRAGE = 2
	};

	////////////////////////////////////////////////////////////
	///DFITCBuySellTypeType:������������
	////////////////////////////////////////////////////////////
	public enum class CLRDFITCBuySellType :short
	{
		///��
		SPD_BUY = 1,
		///��
		SPD_SELL = 2
	};

	////////////////////////////////////////////////////////////
	///DFITCOpenCloseTypeType����ƽ��־��������
	////////////////////////////////////////////////////////////
	public enum class CLRDFITCOpenCloseType
	{
		///����
		SPD_OPEN = 1,
		///ƽ��
		SPD_CLOSE = 2,
		///ƽ��
		SPD_CLOSETODAY = 4,
		///��Ȩִ��
		SPD_EXECUTE = 6,
		///��Ȩ����
		SPD_GIVEUP = 7,
		///��Ȩ��Լ
		SPD_PERFORM = 8,
		///ѯ��
		SPD_OPTQRYPRICE = 9,
		///ǿƽ
		SPD_FORCECLOSE = 12,
		///ǿƽ��
		SPD_FORCECLOSETODAY = 14
	};

	////////////////////////////////////////////////////////////
	///DFITCOrderType:��������
	////////////////////////////////////////////////////////////
	public enum class CLRDFITCOrderType
	{
		///�޼�ί��
		LIMITORDER = 1,
		///�м�ί��
		MKORDER = 2,
		///����ί��
		ARBITRAGE = 4,
		///չ�ڻ���ί��
		EXTENSION = 8,
		///�޼�ֹӯί��
		PROFIT_LIMITORDER = 32,
		///�м�ֹӯί��
		PROFIT_MKORDER = 34,
		///�޼�ֹ��ί��
		LOSS_LIMITORDER = 48,
		///�м�ֹ��ί��
		LOSS_MKORDER = 50
	};

	////////////////////////////////////////////////////////////
	///DFITCAccountLoginResultType:�ʽ��˻���¼���
	////////////////////////////////////////////////////////////
	public enum class CLRDFITCAccountLoginResultType
	{
		///��¼�ɹ�
		LOGIN_SUCCESS = 0,
		///��¼ʧ��
		LOGIN_FAILED = 1,
		///���˳�
		LOGIN_QUIT = 2,
		///δ����
		LOGIN_NOT_OPERATE = 9
	};

	////////////////////////////////////////////////////////////
	///DFITCAccountLogoutResultType:�ʽ��ʺŵǳ����
	////////////////////////////////////////////////////////////
	public enum class CLRDFITCAccountLogoutResultType
	{
		///�ǳ��ɹ�
		LOGOUT_SUCCESS = 0,
		///�ǳ�ʧ��
		LOGOUT_FAILED = 1
	};

	////////////////////////////////////////////////////////////
	///DFITCOrderPropertyType:��������
	////////////////////////////////////////////////////////////
	public enum class CLRDFITCOrderPropertyType :char
	{
		///�޶�������
		SP_NON = '0',
		///FAK����
		SP_FAK = '1',
		///FOK����
		SP_FOK = '2',
		///�м������
		SP_ANYPRICE = '3',
		///�м������ת�޼�
		SP_ANYPRICE_TO_MKORDER = '4',
		///�嵵�м�
		SP_FIVELEVELPRICE = '5',
		///�嵵�м�ת�޼�
		SP_FIVELEVELPRICE_TO_LIMIT = '6',
		///���ż�
		SP_BESTPRICE = '7',
		///���ż�ת�޼�
		SP_BESTPRICE_TO_LIMIT = '8'
	};

	////////////////////////////////////////////////////////////
	///DFITCInsertType:ί�����
	////////////////////////////////////////////////////////////
	public enum class CLRDFITCInsertType
	{
		///��ͨί�е�
		BASIC_ORDER = 0x0001,
		///�Զ���
		AUTO_ORDER = 0x0002
	};

	///������

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCTimeOutField
	{
		DFITCRequestIDType												lRequestID;                   //����ID
	};

	///���󱨵���������(��������)
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCInsertOrderField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^    accountID;          //�ʽ��˻�
		DFITCLocalOrderIDType											localOrderID;		//����ί�к�, ��APIʹ����ά������ͬһ���Ự�в����ظ�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^    instrumentID;       //��Լ����, ֧��Ŀǰ�����ڻ������������к�Լ������������/֣������������Լ
		DFITCPriceType													insertPrice;        //�����۸�, ����������Ϊ�м�ʱ�����ֶβ�������
		DFITCAmountType													orderAmount;        //��������
		DFITCBuySellTypeType											buySellType;        //������־
		DFITCOpenCloseTypeType											openCloseType;      //��ƽ��־
		DFITCSpeculatorType												speculator;         //Ͷ������, ֧��Ͷ�����������ױ�
		DFITCInsertType													insertType;         //�Զ������(Ĭ��Ϊ��ͨ����)
		DFITCOrderTypeType												orderType;          //��������, ֧���޼� ���мۣ���������Լ��֧���м�
		DFITCOrderPropertyType											orderProperty;      //������������, ֧��None��FAK��FOK
		DFITCInstrumentTypeType											instrumentType;     //��Լ����, ��ѡֵ���ڻ�����Ȩ
		DFITCAmountType													minMatchAmount;     //��С�ɽ���
		DFITCReservedType												reservedType2;      //Ԥ���ֶ�2
		DFITCRequestIDType												lRequestID;         //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^    customCategory;     //�Զ������
		DFITCPriceType													profitLossPrice;    //ֹӯֹ��۸�        
	};


	///������������
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCCancelOrderField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�ID
		DFITCSPDOrderIDType                 spdOrderID;                   //��̨ί�к�
		DFITCLocalOrderIDType               localOrderID;                 //����ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
		DFITCRequestIDType                  lRequestID;                   //����ID
		DFITCSessionIDType                  sessionID;                    //�ỰID
	};


	///ί����Ӧ����
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCOrderRspDataRtnField
	{
		DFITCLocalOrderIDType               localOrderID;                 //����ί�к�
		DFITCSPDOrderIDType                 spdOrderID;                   //��̨ί�к�
		DFITCOrderAnswerStatusType          orderStatus;                  //ί��״̬
		DFITCRequestIDType                  lRequestID;                   //����ID
		DFITCPriceType                      fee;                          //������,���ֶν����µ�ʱʹ��
		DFITCPriceType                      margin;                       //���ᱣ֤��,���ֶν����µ�ʱʹ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //�Զ������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ���� 
		DFITCSessionIDType                  sessionID;                    //�ỰID  
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������  
		DFITCBuySellTypeType                buySellType;                  //����    
		DFITCOpenCloseTypeType              openCloseType;                //��ƽ
		DFITCInstrumentTypeType             instrumentType;               //��Լ����
		DFITCSpeculatorType                 speculator;                   //Ͷ�����
		DFITCPriceType                      insertPrice;                  //ί�м�
		DFITCPriceType                      profitLossPrice;              //ֹӯֹ��۸�
		DFITCAmountType                     minMatchAmount;               //��С�ɽ���
		DFITCAmountType                     orderAmount;                  //ί������
		DFITCInsertType                     insertType;                   //�Զ������
		DFITCOrderTypeType                  orderType;                    //��������	
		DFITCOrderPropertyType              orderProperty;                //��������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                     //���ױ���
	};



	///��ѯ�ʽ���������
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCCapitalField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�ID
	};


	///��ѯ�ֲ���������
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCPositionField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
		DFITCInstrumentTypeType             instrumentType;               //��Լ����
		DFITCIsReturnRealizedPNLType        retRealizedPNL;               //�Ƿ񷵻�δ�ֲֺ�Լ��ƽ��ӯ��
	};


	///��������Լ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCExchangeInstrumentField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //����������
		DFITCInstrumentTypeType             instrumentType;               //��Լ����
	};


	///�û���¼��������
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCUserLoginField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                     passwd;                       //����
		DFITCCompanyIDType                  companyID;                    //����ID
	};


	///�û��˳�����
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCUserLogoutField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��ʺ�ID
		DFITCSessionIDType                  sessionID;                    //�ỰID
	};


	///ί�лر�
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCOrderRtnField
	{
		DFITCLocalOrderIDType               localOrderID;                 //����ί�к�
		DFITCSPDOrderIDType                 spdOrderID;                   //��̨ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^                 OrderSysID;                   //�������
		DFITCOrderAnswerStatusType          orderStatus;                  //ί��״̬
		DFITCSessionIDType                  sessionID;                    //�ỰID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       SuspendTime;                  //����ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������ 
		DFITCBuySellTypeType                buySellType;                  //����
		DFITCOpenCloseTypeType              openCloseType;                //��ƽ
		DFITCInstrumentTypeType             instrumentType;               //��Լ����
		DFITCSpeculatorType                 speculator;                   //Ͷ�����
		DFITCPriceType                      insertPrice;                  //ί�м�
		DFITCPriceType                      profitLossPrice;              //ֹӯֹ��۸�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˺�
		DFITCAmountType                     cancelAmount;                 //��������
		DFITCAmountType                     orderAmount;                  //ί������
		DFITCInsertType                     insertType;                   //�Զ������
		DFITCOrderTypeType                  orderType;                    //��������
		DFITCSPDOrderIDType                 extSpdOrderID;                //���������
		DFITCReservedType                   reservedType2;                //Ԥ���ֶ�2	
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //�Զ������
		DFITCOrderPropertyType              orderProperty;                //��������	
		DFITCAmountType                     minMatchAmount;               //��С�ɽ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                     //���ױ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               statusMsg;                    //״̬��Ϣ
		DFITCExtOrderType                   extOrderType;                 //����������
	};


	///�ɽ��ر�
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCMatchRtnField
	{
		DFITCLocalOrderIDType               localOrderID;                 //����ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^                 OrderSysID;                   //�������(�������������)
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^                    matchID;                      //�ɽ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
		DFITCBuySellTypeType                buySellType;                  //����
		DFITCOpenCloseTypeType              openCloseType;                //��ƽ��־
		DFITCPriceType                      matchedPrice;                 //�ɽ��۸�
		DFITCAmountType                     orderAmount;                  //ί������
		DFITCAmountType                     matchedAmount;                //�ɽ�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       matchedTime;                  //�ɽ�ʱ��
		DFITCPriceType                      insertPrice;                  //����
		DFITCSPDOrderIDType                 spdOrderID;                   //��̨ί�к�
		DFITCMatchType                      matchType;                    //�ɽ�����
		DFITCSpeculatorType                 speculator;                   //Ͷ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������ID
		DFITCFeeType                        fee;                          //������
		DFITCSessionIDType                  sessionID;                    //�Ự��ʶ
		DFITCInstrumentTypeType             instrumentType;               //��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˺�
		DFITCOrderAnswerStatusType          orderStatus;                  //�걨���
		DFITCPriceType                      margin;                       //����Ϊ��֤��,ƽ��Ϊ�ⶳ��֤��
		DFITCPriceType                      frozenCapita;                 //�ɽ��ⶳί�ж�����ʽ�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^             adjustmentInfo;               //��ϻ�����ı�֤�������Ϣ,��ʽ:[��Լ����,������־,Ͷ�����,�������;] 
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //�Զ������
		DFITCPriceType                      turnover;                     //�ɽ����
		DFITCOrderTypeType                  orderType;                    //��������
		DFITCInsertType                     insertType;                   //�Զ������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                     //���ױ���
		DFITCProfitLossType                 dateCloseProfitLoss;          //����ƽ��ӯ��
	};


	///�����ر�
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCOrderCanceledRtnField
	{
		DFITCLocalOrderIDType               localOrderID;                 //����ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^                 OrderSysID;                   //�������  
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����     
		DFITCPriceType                      insertPrice;                  //�����۸�  
		DFITCBuySellTypeType                buySellType;                  //��������
		DFITCOpenCloseTypeType              openCloseType;                //��ƽ��־
		DFITCAmountType                     cancelAmount;                 //��������
		DFITCSPDOrderIDType                 spdOrderID;                   //��̨ί�к�
		DFITCSpeculatorType                 speculator;                   //Ͷ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       canceledTime;                 //����ʱ��
		DFITCSessionIDType                  sessionID;                    //�Ự��ʶ
		DFITCOrderAnswerStatusType          orderStatus;                  //�걨���
		DFITCInstrumentTypeType             instrumentType;               //��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˺�
		DFITCAmountType                     orderAmount;                  //ί������   
		DFITCPriceType                      margin;                       //��֤��
		DFITCPriceType                      fee;                          //������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //�Զ������
		DFITCPriceType                      profitLossPrice;              //ֹӯֹ��۸�
		DFITCAmountType                     minMatchAmount;               //��С�ɽ���
		DFITCInsertType                     insertType;                   //�Զ������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                     //���ױ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               statusMsg;                    //״̬��Ϣ
		DFITCOrderPropertyType              orderProperty;                //������������
	};


	///������Ϣ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCErrorRtnField
	{
		DFITCRequestIDType                  requestID;                    //����ID
		DFITCSessionIDType                  sessionID;                    //�Ự��ʶ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˺�
		DFITCErrorIDType                    nErrorID;                     //����ID
		DFITCSPDOrderIDType                 spdOrderID;                   //��̨ί�к�
		DFITCLocalOrderIDType               localOrderID;                 //����ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               errorMsg;                     //������Ϣ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
	};


	///�����ʽ���Ϣ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCCapitalInfoRtnField
	{
		DFITCRequestIDType                  requestID;                    //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��ʺ�
		DFITCEquityType                     preEquity;                    //����Ȩ��
		DFITCEquityType                     todayEquity;                  //���տͻ�Ȩ��
		DFITCProfitLossType                 closeProfitLoss;              //ƽ��ӯ��
		DFITCProfitLossType                 positionProfitLoss;           //�ֲ�ӯ��
		DFITCProfitLossType                 frozenMargin;                 //�����ʽ�
		DFITCProfitLossType                 margin;                       //�ֱֲ�֤��
		DFITCProfitLossType                 fee;                          //����������
		DFITCProfitLossType                 available;                    //�����ʽ�
		DFITCProfitLossType                 withdraw;                     //��ȡ�ʽ�
		DFITCRiskDegreeType                 riskDegree;                   //���ն�
		DFITCPremiumType                    todayPremiumIncome;           //����Ȩ��������
		DFITCPremiumType                    todayPremiumPay;              //����Ȩ���𸶳�
		DFITCPremiumType                    yesterdayPremium;             //��Ȩ�����ո�
		DFITCMarketValueType                optMarketValue;               //��Ȩ��ֵ
		DFITCProfitLossType                 floatProfitLoss;              //����ӯ��
		DFITCProfitLossType                 totFundOut;                   //�ܳ���
		DFITCProfitLossType                 totFundIn;                    //�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]String^                   currencyID;                   //���ִ���
		DFITCProfitLossType                 mortgage;                     //��Ѻ���
		DFITCProfitLossType                 fundMortgageIn;               //����������
		DFITCProfitLossType                 fundMortgageOut;              //�����ʳ����
		DFITCProfitLossType                 fundMortgageAvailable;        //������Ѻ���
	};


	///���سֲ���Ϣ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCPositionInfoRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��ʺ�ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ��
		DFITCBuySellTypeType                buySellType;                  //����
		DFITCPriceType                      openAvgPrice;                 //���־���
		DFITCPriceType                      positionAvgPrice;             //�ֲ־���
		DFITCAmountType                     positionAmount;               //�ֲ���
		DFITCAmountType                     totalAvaiAmount;              //�ܿ���
		DFITCAmountType                     todayAvaiAmount;              //�����
		DFITCAmountType                     lastAvaiAmount;               //�����
		DFITCAmountType                     todayAmount;                  //���
		DFITCAmountType                     lastAmount;                   //���
		DFITCAmountType                     tradingAmount;                //ƽ��ҵ���
		DFITCProfitLossType                 datePositionProfitLoss;       //���гֲ�ӯ��
		DFITCProfitLossType                 dateCloseProfitLoss;          //(����)ƽ��ӯ��
		DFITCProfitLossType                 dPremium;                     //Ȩ����
		DFITCProfitLossType                 floatProfitLoss;              //����ӯ��
		DFITCProfitLossType                 dMargin;                      //ռ�ñ�֤��
		DFITCSpeculatorType                 speculator;                   //Ͷ�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                     //���ױ���
		DFITCPriceType                      preSettlementPrice;           //������
		DFITCInstrumentTypeType             instrumentType;               //��Լ����
		DFITCAmountType                     yesterdayTradingAmount;       //ƽ��ҵ���
		DFITCProfitLossType                 optionValue;                  //��Ȩ��ֵ
	};


	///�û���¼������Ϣ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCUserLoginInfoRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��ʺ�ID
		DFITCAccountLoginResultType         loginResult;                  //��¼���
		DFITCLocalOrderIDType               initLocalOrderID;             //��ʼ����ί�к�
		DFITCSessionIDType                  sessionID;                    //sessionID(�ỰID)
		DFITCErrorIDType                    nErrorID;                     //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               errorMsg;                     //������Ϣ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 256)]String^                       DCEtime;                      //������ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 256)]String^                       SHFETime;                     //������ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 256)]String^                       CFFEXTime;                    //�н���ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 256)]String^                       CZCETime;                     //֣����ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 256)]String^                       INETime;                      //������ʱ��
	};


	///�û��˳�������Ϣ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCUserLogoutInfoRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�ID
		DFITCAccountLogoutResultType        logoutResult;                 //�˳����
		DFITCErrorIDType                    nErrorID;                     //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               errorMsg;                     //������Ϣ
	};


	///������Լ��ѯ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCAbiInstrumentField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //����������
	};


	///������Լ������Ϣ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCAbiInstrumentRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               InstrumentID;                 //��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^             instrumentName;               //��Լ����
		DFITCPriceType                      upperLimitPrice;              //��ͣ���
		DFITCPriceType                      lowerLimitPrice;              //��ͣ���        
		DFITCPriceType                      priceTick;                    //��С�䶯��λ
	};


	///ָ���ĺ�Լ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCSpecificInstrumentField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               InstrumentID;                 //��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������ID
		DFITCInstrumentTypeType             instrumentType;               //��Լ����
		DFITCSpeculatorType                 speculator;                   //Ͷ������
	};


	//****************��Ȩ��չ�����Լ�ر�����*************************
	///ָ���ĺ�Լ��Ϣ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCSpecificInstrumentFieldEX
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^                 FunctionID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               InstrumentID;                 //��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������ID
		DFITCInstrumentTypeType             instrumentType;               //��Լ����
	};
	//*****************************************

	///���鶩�ķ�����Ϣ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCActiveContractField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 1024)]String^             activeContract;               //��Ч��Լ
	};


	///��������Լ������Ϣ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCExchangeInstrumentRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^                VarietyName;                  //Ʒ������
		DFITCInstrumentTypeType             instrumentType;               //��Լ����
		DFITCAmountType                     orderTopLimit;                //�޼�ί������
		DFITCAmountType                     mktOrderTopLimit;             //�м�ί������
		DFITCPriceType                      contractMultiplier;           //��Լ����
		DFITCPriceType                      minPriceFluctuation;          //��С�䶯��λ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 12)]String^         instrumentMaturity;           //��Լ�������
		DFITCPriceType                      upperLimitPrice;              //��ͣ���
		DFITCPriceType                      lowerLimitPrice;              //��ͣ���
		DFITCPriceType                      preClosePrice;                //������
		DFITCPriceType                      preSettlementPrice;           //������
		DFITCPriceType                      settlementPrice;              //�����
		DFITCAmountType                     preOpenInterest;              //��ֲ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^           instrumentPrefix;             //��Լǰ׺
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 12)]String^    instrumentExpiration;         //��Լ������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               underlying;                   //��Ȩ��Ӧ�ı�ĺ�Լ����
		DFITCOptionTypeType                 optionType;                   //��Ȩ����
		DFITCPriceType                      strikePrice;                  //ִ�м۸�
		DFITCRiskDegreeType                 exchangeRiskDegree;           //��������Ȩ��ͱ��Ϸ���ϵ��
		DFITCPriceType                      minMargin;                    //��λ���֣���Ȩ��Լ��С��֤��
		DFITCAmountType                     tradeSize;                    //��Ȩ���ֵ�λ
	};


	///ί�в�ѯ���ݽṹ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCOrderField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�ID
		DFITCInstrumentTypeType             instrumentType;               //��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //�Զ������
		DFITCOrderAnswerStatusType          orderStatus;                  //ί��״̬(�ݲ�֧��)
		DFITCOrderTypeType                  orderType;                    //��������(�ݲ�֧��)
		DFITCSPDOrderIDType                 spdOrderID;                   //��̨ί�к�
		DFITCLocalOrderIDType               localOrderID;                 //����ί�к�
		DFITCSessionIDType                  sessionID;                    //�ỰID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
	};


	///�ɽ���ѯ���ݽṹ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCMatchField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�ID
		DFITCInstrumentTypeType             instrumentType;               //��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //�Զ������
		DFITCOrderTypeType                  orderType;                    //��������(�ݲ�֧��)
		DFITCSPDOrderIDType                 spdOrderID;                   //��̨ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
	};


	///ί�в�ѯ��Ӧ���ݽṹ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCOrderCommRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		DFITCSPDOrderIDType                 spdOrderID;                   //��̨ί�к�
		DFITCOrderAnswerStatusType          orderStatus;                  //ί��״̬
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
		DFITCBuySellTypeType                buySellType;                  //����
		DFITCOpenCloseTypeType              openClose;                    //��ƽ��־
		DFITCPriceType                      insertPrice;                  //ί�м�
		DFITCAmountType                     orderAmount;                  //ί������
		DFITCPriceType                      matchedPrice;                 //�ɽ��۸�
		DFITCAmountType                     matchedAmount;                //�ɽ�����
		DFITCAmountType                     cancelAmount;                 //��������
		DFITCInsertType                     insertType;                   //�Զ������
		DFITCSpeculatorType                 speculator;                   //Ͷ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       commTime;                     //ί��ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       submitTime;                   //�걨ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                     //���ױ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^                  operStation;                  //ί�е�ַ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ͻ���
		DFITCInstrumentTypeType             instrumentType;               //��Լ����
		DFITCSessionIDType                  sessionId;                    //�ỰID
		DFITCReservedType                   reservedType2;                //Ԥ���ֶ�2
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^                 OrderSysID;                   //�������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //�Զ������
		DFITCPriceType                      margin;                       //��֤��
		DFITCPriceType                      fee;                          //������
		DFITCLocalOrderIDType               localOrderID;                 //����ί�к�
		DFITCPriceType                      profitLossPrice;              //ֹ��ֹӯ��
		DFITCOrderTypeType                  orderType;                    //�������
		DFITCOrderPropertyType              orderProperty;                //��������
	};


	///�ɽ���ѯ������Ӧ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCMatchedRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		DFITCSPDOrderIDType                 spdOrderID;                   //��̨ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˺�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
		DFITCBuySellTypeType                buySellType;                  //����
		DFITCOpenCloseTypeType              openClose;                    //��ƽ
		DFITCPriceType                      matchedPrice;                 //�ɽ��۸�
		DFITCAmountType                     matchedAmount;                //�ɽ�����
		DFITCPriceType                      matchedMort;                  //�ɽ����
		DFITCSpeculatorType                 speculator;                   //Ͷ�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       matchedTime;                  //�ɽ�ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^                    matchedID;                    //�ɽ����
		DFITCLocalOrderIDType               localOrderID;                 //����ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                     //���ױ���
		DFITCMatchType                      matchType;                    //�ɽ�����
		DFITCInstrumentTypeType             instrumentType;               //��Լ����
		DFITCSessionIDType                  sessionId;                    //�ỰID
		DFITCReservedType                   reservedType2;                //Ԥ���ֶ�2
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //�Զ������
		DFITCPriceType                      fee;                          //������
		DFITCOrderTypeType                  orderType;                    //��������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^                 OrderSysID;                   //�������
	};


	///���غ�Լ��Ϣ���ݽṹ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCInstrumentRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
		DFITCRatioType                      longMarginRatio;              //��ͷ��֤����
		DFITCRatioType                      shortMarginRatio;             //��ͷ��֤����
		DFITCPriceType                      longMarginRatioByVolume;      //��ͷ��֤���(����)
		DFITCPriceType                      shortMarginRatioByVolume;     //��ͷ��֤���(����)
		DFITCRatioType                      openFeeVolRatio;              //���������� ����������
		DFITCRatioType                      closeFeeVolRatio;             //ƽ�������� ����������
		DFITCRatioType                      closeTodayFeeVolRatio;        //ƽ�������� ����������
		DFITCRatioType                      openFeeAmtRatio;              //������������ ��������
		DFITCRatioType                      closeFeeAmtRatio;             //ƽ���������� ��������
		DFITCRatioType                      closeTodayFeeAmtRatio;        //ƽ���������� ��������
		DFITCAmountType                     orderTopLimit;                //�޼�ί������
		DFITCPriceType                      contractMultiplier;           //��Լ����
		DFITCPriceType                      minimumPriceChange;           //��С�䶯��λ
		DFITCInstrumentTypeType             instrumentType;               //��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 12)]String^         instrumentMaturity;           //��Լ�������
		DFITCComputeModeType                computeMode;                  //���㷽ʽ             
		DFITCPriceType                      atMoneyNorm;                  //ƽֵ������
		DFITCPriceType                      upperLimitPrice;              //��ͣ���
		DFITCPriceType                      lowerLimitPrice;              //��ͣ���
		DFITCPriceType                      preClosePrice;                //������
		DFITCPriceType                      preSettlementPrice;           //������
		DFITCPriceType                      settlementPrice;              //�����
		DFITCAmountType                     preOpenInterest;              //��ֲ���
		DFITCRatioType                      optExecRatio;                 //��Ȩ����Ȩ������ �ڻ����������
		DFITCRatioType                      optExecRatioPerVol;           //��Ȩ����Ȩ������ �ڻ����������
	};


	///�������
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCDepthMarketDataField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       tradingDay;                   //������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               exchangeInstID;               //��Լ�ڽ������Ĵ���
		DFITCPriceType                      lastPrice;                    //���¼�
		DFITCPriceType                      preSettlementPrice;           //�ϴν����
		DFITCPriceType                      preClosePrice;                //������
		DFITCAmountType                     preOpenInterest;              //��ֲ���
		DFITCPriceType                      openPrice;                    //����
		DFITCPriceType                      highestPrice;                 //��߼�
		DFITCPriceType                      lowestPrice;                  //��ͼ�
		DFITCAmountType                     Volume;                       //�ɽ�����
		DFITCPriceType                      turnover;                     //�ɽ����
		DFITCAmountType                     openInterest;                 //�ֲ���
		DFITCPriceType                      closePrice;                   //������
		DFITCPriceType                      settlementPrice;              //���ν����
		DFITCPriceType                      upperLimitPrice;              //��ͣ���
		DFITCPriceType                      lowerLimitPrice;              //��ͣ���
		DFITCDeltaType                      preDelta;                     //����ʵ��
		DFITCDeltaType                      currDelta;                    //����ʵ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       UpdateTime;                   //����޸�ʱ��
		DFITCMilliSecType                   UpdateMillisec;               //����޸ĺ���
		DFITCPriceType                      BidPrice1;                    //�����һ
		DFITCVolumeType                     BidVolume1;                   //������һ
		DFITCPriceType                      AskPrice1;                    //������һ
		DFITCVolumeType                     AskVolume1;                   //������һ
		DFITCPriceType                      BidPrice2;                    //����۶�
		DFITCVolumeType                     BidVolume2;                   //��������
		DFITCPriceType                      AskPrice2;                    //�����۶�
		DFITCVolumeType                     AskVolume2;                   //��������
		DFITCPriceType                      BidPrice3;                    //�������
		DFITCVolumeType                     BidVolume3;                   //��������
		DFITCPriceType                      AskPrice3;                    //��������
		DFITCVolumeType                     AskVolume3;                   //��������
		DFITCPriceType                      BidPrice4;                    //�������
		DFITCVolumeType                     BidVolume4;                   //��������
		DFITCPriceType                      AskPrice4;                    //��������
		DFITCVolumeType                     AskVolume4;                   //��������
		DFITCPriceType                      BidPrice5;                    //�������
		DFITCVolumeType                     BidVolume5;                   //��������
		DFITCPriceType                      AskPrice5;                    //��������
		DFITCVolumeType                     AskVolume5;                   //��������
		DFITCPriceType                      AveragePrice;                 //���վ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       XSpeedTime;                   //��̨ϵͳʱ��
	};

	///********************************��Ȩ��չ����************************************


	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCMarketDataFieldEx
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^                FunctionID;                    //���ܺ�   
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                      tradingDay;                    //���� 2014-04-01   
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                      UpdateTime;                    //ʱ�� 11:01:29
		DFITCMilliSecType                  UpdateMillisec;                //���� 000 
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^              instrumentID;                  //��Ȩ��Լ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 128)]String^             ExtMarketData;                 //��չ��������	
	};
	///********************************************************************************


	//�Զ����������
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCCustomMarketDataField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������
		DFITCVolumeType                     bidVolume1;                   //��һ��
		DFITCPriceType                      bidPrice1;                    //��һ��(�Ҽۼ۲�)
		DFITCVolumeType                     askVolume1;                   //��һ��
		DFITCPriceType                      askPrice1;                    //��һ��(�Լۼ۲�)
		DFITCPriceType                      lastPrice;                    //���¼ۼ۲�
	};

	///��ѯ�ֲ���ϸ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCPositionDetailField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
		DFITCInstrumentTypeType             instrumentType;               //��Լ����
	};


	///��ѯ�ֲ���ϸ��Ӧ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCPositionDetailRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��ʺ�ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ��
		DFITCBuySellTypeType                buySellType;                  //����
		DFITCPriceType                      openPrice;                    //���ּ�
		DFITCAmountType                     volume;                       //����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^                    matchID;                      //�ɽ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       matchedDate;                  //�ɽ�����
		DFITCProfitLossType                 datePositionProfitLoss;       //���гֲ�ӯ��
		DFITCProfitLossType                 dateCloseProfitLoss;          //����ƽ��ӯ��
		DFITCProfitLossType                 floatProfitLoss;              //����ӯ��
		DFITCProfitLossType                 dMargin;                      //ռ�ñ�֤��
		DFITCSpeculatorType                 speculator;                   //Ͷ�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                     //���ױ���
		DFITCPriceType                      preSettlementPrice;           //������
		DFITCInstrumentTypeType             instrumentType;               //��Լ����
		DFITCSPDOrderIDType                 spdOrderID;                   //��̨ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //�Զ������
		DFITCAmountType                     closeOrderVol;                //ƽ��ί������
		DFITCAmountType                     closeMatchVol;                //ƽ�ֳɽ�����
		DFITCPositionDateType               positionDateType;             //�ֲ���������
	};


	///�û��¼�֪ͨ��Ϣ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCTradingNoticeInfoField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��ʺ�ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 256)]String^                       SendTime;                     //����ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 501)]String^                    FieldContent;                 //��Ϣ����
		DFITCNoticeType                     noticeType;                   //��Ϣ����
	};


	///��Լ����״̬֪ͨ��Ϣ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCInstrumentStatusField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 ExchangeID;                   //����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               InstrumentID;                 //��Լ����
		DFITCInstrumentStatusType           InstrumentStatus;             //��Լ����״̬
		DFITCTradingSegmentSNType           TradingSegmentSN;             //���׽׶α��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 256)]String^                       EnterTime;                    //���뱾״̬ʱ��
		DFITCInstStatusEnterReasonType      EnterReason;                  //���뱾״̬ԭ��
	};


	///�û������޸�
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCResetPwdField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��ʺ�ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                     oldpasswd;                    //������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                     newpasswd;                    //������
	};


	///�û������޸ķ�����Ϣ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCResetPwdRspField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�ID
		DFITCExecStateType                  execState;                    //״̬��־
	};


	///�˵�ȷ��
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCBillConfirmField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��ʺ�ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       date;                         //ȷ������  ��ʽ��yyyy.mm.dd
		DFITCConfirmMarkType                confirmFlag;                  //ȷ�ϱ�־
	};


	///�˵�ȷ����Ӧ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCBillConfirmRspField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�ID
		DFITCExecStateType                  execState;                    //״̬��־
	};


	///���ױ����ѯ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryTradeCodeField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�ID
	};


	///���ױ����ѯ��Ӧ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryTradeCodeRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeCode;                 //����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                     //���ױ��� 
		DFITCClientStatusType               clientStatus;                 //���ױ���״̬
		DFITCSpeculatorType                 clientIDType;                 //���ױ�������
	};


	///��ӯ�����Ƿ���㵽Ȩ����
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCEquityComputModeRtnField
	{
		DFITCCapControlModeType             capConMode;                   //�ʽ���Ʒ�ʽ,�÷�ʽ��Ҫ�û���λ�ж�,����Ϊ�������
		DFITCPriceNoteType                  priceNote;                    //����ڻ��۸�˵��
	};


	///��ѯ�˵�
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryBillField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       date;                         //��ѯ����   ��ʽ��yyyy.mm.dd
	};


	///��ѯ�˵���Ӧ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryBillRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 1024)]String^                    message;                      //������Ϣ
	};


	///����IDȷ������
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCProductField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                  productID;                    //��Ʒ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^           vendorID;                     //�����Ӧ�̱�� 
	};


	///����IDȷ����Ӧ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCProductRtnField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                  productID;                    //��Ʒ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^           vendorID;                     //�����Ӧ��
		DFITCProductOnlineCountType         productOnlineCount;           //��Ʒ��������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 20)]String^                 brokerInfoName;               //�ڻ���˾����
		DFITCFrontIDType                    frontID;                      //ǰ�û�ID
	};


	///��ѯ����������
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCTradingDayField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
	};


	///������������Ӧ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCTradingDayRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       date;                         //������
	};


	///ѯ��֪ͨ��������
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteSubscribeField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˺�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������
	};

	///ѯ��֪ͨ������Ӧ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteSubscribeRspField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		DFITCExecStateType                  subscribeFlag;                //����״̬
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������
	};

	///ѯ��֪ͨ�˶�����
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteUnSubscribeField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˺�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������
	};

	///ѯ��֪ͨ�˶���Ӧ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteUnSubscribeRspField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		DFITCExecStateType                  subscribeFlag;                //�˶�״̬
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������
	};

	///ѯ��֪ͨ���Ļر�
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteSubscribeRtnField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                    quoteID;                      //ѯ�۱��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
		DFITCSourceType                     source;                       //��Դ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       quoteTime;                    //ѯ��ʱ��
	};

	///ѯ��֪ͨ��ѯ����
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryQuoteNoticeField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˺�
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
	};

	///ѯ��֪ͨ��ѯ��Ӧ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryQuoteNoticeRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                    quoteID;                      //ѯ�۱��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
		DFITCSourceType                     source;                       //��Դ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       quoteTime;                    //ѯ��ʱ��
	};

	///�����̱�������
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteInsertField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˺�
		DFITCRequestIDType                  lRequestID;                   //����ID
		DFITCLocalOrderIDType               localOrderID;                 //����ί�к�
		DFITCInsertType                     insertType;                   //�Զ������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                    quoteID;                      //ѯ�۱��
		DFITCInstrumentTypeType             instrumentType;               //��Լ���� 
		DFITCAmountType                     bOrderAmount;                 //������������
		DFITCAmountType                     sOrderAmount;                 //��������������
		DFITCPriceType                      bInsertPrice;                 //ί�м۸���         
		DFITCPriceType                      sInsertPrice;                 //ί�м۸�����          
		DFITCOpenCloseTypeType              bOpenCloseType;               //��ƽ��־����  
		DFITCOpenCloseTypeType              sOpenCloseType;               //��ƽ��־������
		DFITCSpeculatorType                 bSpeculator;                  //Ͷ�������       
		DFITCSpeculatorType                 sSpeculator;                  //Ͷ���������          
		DFITCStayTimeType                   stayTime;                     //ͣ��ʱ�䣬��֧��֣�ݡ��������������Ϊ0 
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //�Զ������
	};



	///�����̱�����Ӧ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteRspField
	{
		DFITCLocalOrderIDType               localOrderID;                 //����ί�к�              
		DFITCSPDOrderIDType                 spdOrderID;                   //��̨ί�к�                
		DFITCRequestIDType                  lRequestID;                   //����ID                    
		DFITCPriceType                      fee;                          //������(������ʹ��)            
		DFITCPriceType                      margin;                       //��֤��(������ʹ��)
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       orderTime;                    //ί��ʱ��(������ʹ��)  
		DFITCOrderAnswerStatusType          orderStatus;                  //ί��״̬
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //�Զ������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˺�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                    quoteID;                      //ѯ�۱��
		DFITCSessionIDType                  sessionID;                    //�ỰID 
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                     //���ױ���
	};


	///�����̱����ر�
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteRtnField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                    //������                   
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                      //���ױ���  
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^                 orderSysID;                    //�������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                  //��Լ����                   
		DFITCLocalOrderIDType               localOrderID;                  //����ί�к�                
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                   seatCode;                      //ϯλ����                  
		DFITCOpenCloseTypeType              bOpenCloseType;                //��ƽ��־����          
		DFITCOpenCloseTypeType              sOpenCloseType;                //��ƽ��־������             
		DFITCSpeculatorType                 speculator;                    //Ͷ�����                       
		DFITCAmountType                     bOrderAmount;                  //ί����������            
		DFITCAmountType                     sOrderAmount;                  //ί������������           
		DFITCPriceType                      bInsertPrice;                  //ί�м�  ����               
		DFITCPriceType                      sInsertPrice;                  //ί�м�  ������               
		DFITCSPDOrderIDType                 spdOrderID;                    //��̨ί�к�                               
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                     //�ʽ��˺�                     
		DFITCInstrumentTypeType             instrumentType;                //��Լ����                  
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       suspendTime;                   //�ҵ�ʱ��                               
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^               entrusTeller;                  //ί�й�Ա  
		DFITCOrderAnswerStatusType          orderStatus;                   //ί��״̬ 
		DFITCSessionIDType                  sessionID;                     //�ỰID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                    quoteID;                       //ѯ�۱��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               errorMsg;                      //������Ϣ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;                //�Զ������
	};



	///�����̳����ر�
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteCanceledRtnField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                    //������                   
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                      //���ױ���  
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^                 orderSysID;                    //�������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                  //��Լ����                   
		DFITCLocalOrderIDType               localOrderID;                  //����ί�к�                
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                   seatCode;                      //ϯλ����                  
		DFITCOpenCloseTypeType              bOpenCloseType;                //��ƽ��־����          
		DFITCOpenCloseTypeType              sOpenCloseType;                //��ƽ��־������             
		DFITCSpeculatorType                 speculator;                    //Ͷ�����                       
		DFITCSPDOrderIDType                 spdOrderID;                    //��̨ί�к�                               
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                     //�ʽ��˺�                     
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^               entrusTeller;                  //ί�й�Ա       
		DFITCOrderAnswerStatusType          orderStatus;                   //ί��״̬ 
		DFITCAmountType                     cancelAmount;                  //��������                              
		DFITCPriceType                      fee;                           //�ⶳ������                  
		DFITCPriceType                      margin;                        //�ⶳ��֤�� 
		DFITCSessionIDType                  sessionID;                     //�ỰID
		DFITCBuySellTypeType                buySellType;                   //������־
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                    quoteID;                       //ѯ�۱��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       canceledTime;                  //����ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;                //�Զ������
	};



	///�����̳ɽ��ر�
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteMatchRtnField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                     //���ױ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                   seatCode;                     //ϯλ����
		DFITCLocalOrderIDType               localOrderID;                 //����ί�к�
		DFITCOpenCloseTypeType              openCloseType;                //��ƽ��־
		DFITCSpeculatorType                 speculator;                   //Ͷ�����  
		DFITCSPDOrderIDType                 spdOrderID;                   //��̨ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^                 OrderSysID;                   //�������(�������������)
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^                    matchID;                      //�ɽ����
		DFITCAmountType                     matchedAmount;                //�ɽ�����
		DFITCPriceType                      matchedPrice;                 //�ɽ��۸�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˺�
		DFITCPriceType                      turnover;                     //�ɽ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^               entrusTeller;                 //ί�й�Ա
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       matchedTime;                  //�ɽ�ʱ��
		DFITCFeeType                        fee;                          //������
		DFITCPriceType                      insertPrice;                  //ί�м۸�
		DFITCAmountType                     orderAmount;                  //ί������
		DFITCOrderAnswerStatusType          orderStatus;                  //�걨���
		DFITCPriceType                      margin;                       //����Ϊ��֤��,ƽ��Ϊ�ⶳ��֤��
		DFITCBuySellTypeType                buySellType;                  //����
		DFITCAmountType                     closeTodayAmount;             //ƽ������
		DFITCPriceType                      closePrice;                   //ƽ�ֽ��
		DFITCPriceType                      closeTodayPrice;              //ƽ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^             adjustmentInfo;               //��ϻ�����ı�֤�������Ϣ,��ʽ:[��Լ����,������־,Ͷ�����,�������;] 
		DFITCPriceType                      frozenCapita;                 //�ɽ��ⶳί�ж�����ʽ�
		DFITCProfitLossType                 dateCloseProfitLoss;          //����ƽ��ӯ��
		DFITCInstrumentTypeType             instrumentType;               //��Լ����
		DFITCSessionIDType                  sessionID;                    //�Ự��ʶ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 128)]String^          largeMarginDirect;            //��߱�֤����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                    quoteID;                      //ѯ�۱��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //�Զ������
	};


	///������������
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCCancelAllOrderField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //����������(Ŀǰֻ֧�ִ�����)
	};

	///����������Ӧ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCCancelAllOrderRspField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�ID
		DFITCOrderAnswerStatusType          orderStatus;                  //ί��״̬
	};

	///ѯ������
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCForQuoteField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
	};

	///ѯ��������Ӧ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCForQuoteRspField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		DFITCSPDOrderIDType                 spdOrderID;                   //��̨ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       commTime;                     //ί��ʱ��
	};

	///ѯ�ۻر�
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCForQuoteRtnField
	{
		DFITCSPDOrderIDType                 spdOrderID;                   //��̨ί�к�
		DFITCSessionIDType                  sessionID;                    //�ỰID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˺�
		DFITCOrderAnswerStatusType          orderStatus;                  //ί��״̬
	};

	///�����̱���ί�в�ѯ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteOrderField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
		DFITCLocalOrderIDType               localOrderID;                 //����ί�к�
		DFITCSPDOrderIDType                 spdOrderID;                   //��̨ί�к�
		DFITCOrderAnswerStatusType          orderStatus;                  //ί��״̬
	};

	///�����̱��۲�ѯ��Ӧ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteOrderRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		DFITCSPDOrderIDType                 spdOrderID;                   //��̨ί�к�
		DFITCOrderAnswerStatusType          orderStatus;                  //ί��״̬
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
		DFITCPriceType                      margin;                       //��֤��
		DFITCPriceType                      fee;                          //������
		DFITCLocalOrderIDType               localOrderID;                 //����ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ͻ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       commTime;                     //ί��ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       submitTime;                   //�걨ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������ID
		DFITCAmountType                     bOrderAmount;                 //ί����������
		DFITCAmountType                     bMatchedAmount;               //�ɽ���������
		DFITCAmountType                     bCancelAmount;                //������������
		DFITCPriceType                      bInsertPrice;                 //ί�м۸���
		DFITCPriceType                      bMatchedPrice;                //�ɽ��۸���
		DFITCOpenCloseTypeType              bOpenCloseType;               //��ƽ��־����
		DFITCAmountType                     sOrderAmount;                 //ί������������
		DFITCAmountType                     sMatchedAmount;               //�ɽ�����������
		DFITCAmountType                     sCancelAmount;                //��������������
		DFITCPriceType                      sInsertPrice;                 //ί�м۸�����
		DFITCPriceType                      sMatchedPrice;                //�ɽ��۸�����
		DFITCOpenCloseTypeType              sOpenCloseType;               //��ƽ��־������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^                  operStation;                  //����վ��
		DFITCSessionIDType                  sessionID;                    //�ỰID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                    quoteID;                      //ѯ�۱��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //�Զ������
	};

	///��ѯת������
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryTransferBankField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                     //�ʽ��˺�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                     bankID;                        //���д���
		DFITCRequestIDType                  lRequestID;                    //����ID
	};

	///ת��������Ӧ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCTransferBankRspField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                     //�ͻ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                     bankID;                        //���д���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                bankAccount;                   //�����˺�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]String^                   currency;                      //����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       registDate;                    //�Ǽ�����
		DFITCRequestIDType                  lRequestID;                    //����ID
	};

	///��ѯת����ˮ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryTransferSerialField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                     //�ʽ��˺�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                     bankID;                        //���д���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                bankAccount;                   //�����˺�
		DFITCRequestIDType                  lRequestID;                    //����ID
	};

	///ת����ˮ��Ӧ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCTransferSerialRspField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                     //�ʽ��˺�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                     bankID;                        //���д���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                bankAccount;                   //�����˺�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]String^                   currency;                      //���ִ���
		DFITCApplyNumberType                applyNum;                      //�����
		DFITCTransferType                   type;                          //ת��ҵ�����
		DFITCPriceType                      tradeAmount;                   //ת�˽��
		DFITCPriceType                      curFutAccountFund;             //�����ʽ����
		DFITCSerialType                     bankSerialNum;                 //������ˮ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 256)]String^                 reqTransferTime;               //����ת��ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 256)]String^                 dealTransferTime;              //ת�˳ɹ�ʱ��
		DFITCProcResultType                 procResult;                    //ת�˴�����
		DFITCRequestIDType                  lRequestID;                    //����ID
	};

	///�ʽ�ת��������Ϣ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCReqTransferField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                     bankID;                        //���д���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                bankAccount;                   //�����˺�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                     bankPassword;                  //��������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                     //Ͷ�����˺�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                     password;                      //�ڻ�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]String^                   currency;                      //���ִ���
		DFITCPriceType                      tradeAmount;                   //ת�˽��
		DFITCRequestIDType                  lRequestID;                    //����ID
	};

	///�ʽ�ת����Ӧ��Ϣ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCTransferRspField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                     bankID;                        //���д���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                bankAccount;                   //�����˺�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                     //Ͷ�����˺�
		DFITCPriceType                      tradeAmount;                   //ת�˽��
		DFITCApplyNumberType                applyNumber;                   //ת�������
		DFITCRequestIDType                  lRequestID;                    //����ID
	};

	///�ʽ�ת��֪ͨ��Ϣ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCTransferRtnField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                     //Ͷ�����˺�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                     bankID;                        //���д���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                bankAccount;                   //�����˺�
		DFITCTransferType                   type;                          //ת�����
		DFITCPriceType                      tradeAmount;                   //ת�˽��
		DFITCSerialType                     bankSerialNum;                 //������ˮ��
		DFITCApplyNumberType                applyNumber;                   //ת�������
		DFITCSessionIDType                  sessionID;                     //�ỰID
	};

	///���л���ϯ����������֪ͨ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCRepealRtnField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                     //Ͷ�����˺�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                     bankID;                        //���д���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                bankAccount;                   //�����˺�
		DFITCTransferType                   type;                          //ת�����
		DFITCPriceType                      tradeAmount;                   //ת�˽��
		DFITCSerialType                     bankSerialNum;                 //������ˮ��
		DFITCSerialType                     repealSerial;                  //��������ˮ��
	};

	///����״̬��ѯ����
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryExchangeStatusField
	{
		DFITCRequestIDType                  lRequestID;                    //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                    //����������
	};

	///������״̬��ѯ��Ӧ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCExchangeStatusRspField
	{
		DFITCRequestIDType                  lRequestID;                    //����ID
		DFITCExchangeStatusType             exchangeStatus;                //������״̬
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                    //����������
	};

	///������״̬֪ͨ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCExchangeStatusRtnField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
		DFITCExchangeStatusType             exchangeStatus;               //������״̬
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 256)]String^                       enterTime;                    //���뱾״̬ʱ��
		DFITCInstStatusEnterReasonType      enterReason;                  //���뱾״̬ԭ��
	};

	///�����ѯ����
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryDepthMarketDataField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������
	};

	///��ѯѯ������
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryForQuoteField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˻�ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������
	};

	///��ѯѯ����Ӧ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryForQuoteRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //�ʽ��˺�
		DFITCSPDOrderIDType                 spdOrderID;                   //��̨ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       SuspendTime;                  //����ʱ��
		DFITCOrderAnswerStatusType          orderStatus;                  //ί��״̬
	};

	///��ѯ����
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryExchangeRateField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]String^                   fromCurrencyID;               //Դ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]String^                   toCurrencyID;                 //Ŀ�����
	};

	///��ѯ������Ӧ
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCExchangeRateField
	{
		DFITCRequestIDType                  lRequestID;                   //����ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]String^                   fromCurrencyID;               //Դ����
		DFITCCurrencyUnitType               fromCurrencyUnit;             //Դ���ֵ�λ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]String^                   toCurrencyID;                 //Ŀ�����
		DFITCExchangeRateType               exchangeRate;                 //����
	};

	///���鴥������
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCPricesTriggerField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //�ʽ��˻�
		DFITCLocalOrderIDType           localOrderID;       //����ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID;       //��Լ����
		DFITCPriceType                  insertPrice;        //ί�м۸�
		DFITCAmountType                 orderAmount;        //ί������
		DFITCSpeculatorType             speculator;         //Ͷ������
		DFITCExtOrderPriceTypeType      orderType;          //��������������
		DFITCBuySellTypeType            buySellType;        //������־
		DFITCOpenCloseTypeType          openCloseType;      //��ƽ��־
		DFITCRequestIDType              lRequestID;         //����ID 
		DFITCCompareFlagType            compareFlag;        //�Ƚϱ�־(�۸�)
		DFITCPriceType                  comparePrice;       //�����۸�(��������Ϊ����۸���ڻ�С�ڵ��ڴ����۸�)
		DFITCPriceReferenceType         priceReference;     //�۸����
		DFITCBreakDownTimesType         breakDownTimes;     //��������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   validate;           //��Ч����(yyyy.mm.dd,�ݲ�֧��)
		DFITCFrozenTypeType             frozentype;         //�Ƿ񶳽��ʽ�����
		DFITCInstrumentTypeType         instrumentType;     //��Լ����
		DFITCAmountType                 limitAmount;        //��������
		DFITCCompareFlagType            qtyCmpFlag;         //�Ƚϱ�־(����)
		DFITCTriggerType                triggerType;        //��������	
		DFITCBreakDownTypeType          breakDownType;      //��������			
	};

	///���鴥�����޸�����
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCPricesTriggerModifyField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //�ʽ��˻�
		DFITCRequestIDType              lRequestID;         //����ID
		DFITCLocalOrderIDType           localOrderID;       //����ί�к�
		DFITCSPDOrderIDType             extSpdOrderID;      //���������		
		DFITCPriceType                  comparePrice;       //�����۸�
		DFITCBreakDownTimesType         breakDownTimes;     //��������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   validate;           //��Ч����(yyyy.mm.dd)
	};

	///�ɽ���������
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCMatchTriggerField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //�ʽ��˻�
		DFITCRequestIDType              lRequestID;         //����ID 
		DFITCLocalOrderIDType           localOrderID;       //����ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID;       //��Լ����
		DFITCPriceType                  insertPrice;        //ί�м۸�
		DFITCAmountType                 orderAmount;        //ί������
		DFITCSpeculatorType             speculator;         //Ͷ������
		DFITCBuySellTypeType            buySellType;        //������־
		DFITCOpenCloseTypeType          openCloseType; 	    //��ƽ��־
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           trigInstrumentID;   //������Լ����
		DFITCPriceType                  trigInsertPrice;    //ί�м۸�
		DFITCAmountType                 trigOrderAmount;    //ί������
		DFITCSpeculatorType             trigSpeculator;     //Ͷ������
		DFITCBuySellTypeType            trigBuySellType;    //������־
		DFITCOpenCloseTypeType          trigOpenCloseType;  //��ƽ��־
		DFITCFrozenTypeType             frozentype;         //��������
	};

	///�ɽ������޸�
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCMatchTriggerModifyField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //�ʽ��˻�
		DFITCRequestIDType              lRequestID;         //����ID 
		DFITCLocalOrderIDType           localOrderID;       //����ί�к�
		DFITCSPDOrderIDType             extSpdOrderID;      //���������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           trigInstrumentID;   //������Լ����
		DFITCPriceType                  trigInsertPrice;    //ί�м۸�
		DFITCAmountType                 trigOrderAmount;    //ί������
		DFITCBuySellTypeType            buySellType;        //������־
		DFITCOpenCloseTypeType          openCloseType;      //��ƽ��־
	};

	///ֹ��ֹӯ������
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)] 
	public value struct CLRDFITCProfitLossField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //�ʽ��˻�
		DFITCRequestIDType              lRequestID;         //����ID 
		DFITCLocalOrderIDType           localOrderID;       //����ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID;       //��Լ����
		DFITCPriceType                  insertPrice;        //ί�м۸�
		DFITCAmountType                 orderAmount;        //ί������
		DFITCSpeculatorType             speculator;         //Ͷ������
		DFITCBuySellTypeType            buySellType;        //������־
		DFITCOpenCloseTypeType          openCloseType;      //��ƽ��־
		DFITCPriceType                  comparePriceFall;   //�µ������۲�
		DFITCPriceType                  insertPriceFall;    //�µ�ί�м۲�
		DFITCAddPriceTimesType          addPriceTimesFall;  //�µ�׷�۴���
		DFITCOrderTypeType              orderTypeFall;      //�µ���������
		DFITCPriceType                  comparePriceRise;   //���Ǵ����۲�
		DFITCPriceType                  insertPriceRise;    //����ί�м۲�
		DFITCAddPriceTimesType          addPriceTimesRise;  //����׷�۴���
		DFITCOrderTypeType              orderTypeRise;      //���Ǳ�������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   validate;           //��Ч����
	};

	///ֹ��ֹӯ�޸�����
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCProfitLossModifyField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //�ʽ��˻�
		DFITCRequestIDType              lRequestID;         //����ID 
		DFITCLocalOrderIDType           localOrderID;       //����ί�к�
		DFITCSPDOrderIDType             extSpdOrderID;      //���������
		DFITCPriceType                  comparePriceFall;   //�µ������۲�
		DFITCPriceType                  insertPriceFall;    //�µ�ί�м۲�
		DFITCAddPriceTimesType          addPriceTimesFall;  //�µ�׷�۴���
		DFITCPriceType                  comparePriceRise;   //���Ǵ����۲�
		DFITCPriceType                  insertPriceRise;    //����ί�м۲�
		DFITCAddPriceTimesType          addPriceTimesRise;  //����׷�۴���
	};

	///��ϴ�����������
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)] 
	public value struct CLRDFITCArbitrageField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //�ʽ��˻�
		DFITCRequestIDType              lRequestID;         //����ID 
		DFITCLocalOrderIDType           localOrderID;       //����ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID;       //��Լ����1
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID2;      //��Լ����2
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   validate;           //��Ч����
		DFITCPriceType                  insertPrice;        //ƫ����
		DFITCAmountType                 orderAmount;        //ί������
		DFITCSpeculatorType             speculator;         //Ͷ������
		DFITCBuySellTypeType            buySellType;        //������־
		DFITCOpenCloseTypeType          openCloseType;      //��ƽ��־
		DFITCPriceType                  insertPrice2;       //ƫ����2
		DFITCAmountType                 orderAmount2;       //ί������2
		DFITCSpeculatorType             speculator2;        //Ͷ������2
		DFITCBuySellTypeType            buySellType2;       //������־2
		DFITCOpenCloseTypeType          openCloseType2;     //��ƽ��־2
		DFITCPriceType                  priceMargin;        //�۲�
		DFITCMinEntryType               minEntry;           //��С��������
		DFITCSplitContinueType          splitContinue;      //�����Ƿ����
		DFITCPriceType                  deviatePrice;       //ƫ����
		DFITCArbitrageTypeType          arbitrageType;      //��������
	};

	///��ϴ������޸�����
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCArbitrageModifyField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //�ʽ��˻�
		DFITCRequestIDType              lRequestID;         //����ID 
		DFITCLocalOrderIDType           localOrderID;       //����ί�к�
		DFITCSPDOrderIDType             extSpdOrderID;      //���������
		DFITCPriceType                  insertPrice;        //ƫ����1
		DFITCPriceType                  insertPrice2;       //ƫ����2
		DFITCPriceType                  priceMargin;        //�۲�
		DFITCMinEntryType               minEntry;           //��С��������
		DFITCSplitContinueType          splitContinue;      //�����Ƿ����
		DFITCPriceType                  deviatePrice;       //ƫ����
	};

	///��������ѯ����
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryExtOrderField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //�ʽ��˻�
		DFITCRequestIDType              lRequestID;         //����ID
		DFITCSPDOrderIDType             extSpdOrderID;      //���������(�ݲ�֧��)
		DFITCExtOrderType               extOrderType;       //����������
	};

	///��������������
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCCancelExtOrderField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //�ʽ��˻�
		DFITCRequestIDType              lRequestID;         //����ID 
		DFITCLocalOrderIDType           localOrderID;       //����ί�к�
		DFITCSPDOrderIDType             extSpdOrderID;      //���������
		DFITCExtOrderType               extOrderType;       //����������
	};


	///���鴥�����ر�
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCPricesTriggerRtnField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //�ʽ��˻�
		DFITCLocalOrderIDType           localOrderID;       //����ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID;       //��Լ����
		DFITCPriceType                  insertPrice;        //ί�м۸�
		DFITCAmountType                 orderAmount;        //ί������
		DFITCSpeculatorType             speculator;         //Ͷ������
		DFITCExtOrderPriceTypeType      extOrderPriceType;  //��������������
		DFITCBuySellTypeType            buySellType;        //������־
		DFITCOpenCloseTypeType          openCloseType;      //��ƽ��־
		DFITCCompareFlagType            compareFlag;        //�Ƚϱ�־
		DFITCPriceType                  comparePrice;       //�����۸�
		DFITCPriceReferenceType         priceReference;     //�۸����
		DFITCBreakDownTimesType         breakDownTimes;     //��������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   modifiedtime;       //�޸�ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   commTime;           //ί��ʱ��
		DFITCSPDOrderIDType             spdOrderID;         //��̨ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   canceledTime;       //����ʱ��
		DFITCFrozenTypeType             frozentype;         //��������
		DFITCSPDOrderIDType             extSpdOrderID;      //���������
		DFITCProfitLossType             frozenMargin;       //�����ʽ�
		DFITCAmountType                 frozenAmount;       //��������
		DFITCOrderAnswerStatusType      orderStatus;        //ί��״̬
		DFITCSessionIDType              sessionID;          //�ỰID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           statusMsg;          //״̬��Ϣ
		DFITCAmountType                 limitAmount;        //��������
		DFITCCompareFlagType            qtyCmpFlag;         //�Ƚϱ�־(����)
		DFITCTriggerType                triggerType;        //��������	
		DFITCBreakDownTypeType          breakDownType;      //��������	
		DFITCExtOrderTriggerStatusType  orderTriggerStatus; //����������״̬
	};


	///��ѯ���鴥��ί��
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryPricesTriggerField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //�ʽ��˻�
		DFITCLocalOrderIDType           localOrderID;       //����ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID;       //��Լ����
		DFITCPriceType                  insertPrice;        //ί�м۸�
		DFITCAmountType                 orderAmount;        //ί������
		DFITCSpeculatorType             speculator;         //Ͷ������
		DFITCOrderTypeType              orderType;          //��������
		DFITCBuySellTypeType            buySellType;        //������־
		DFITCOpenCloseTypeType          openCloseType;      //��ƽ��־
		DFITCRequestIDType              lRequestID;         //����ID 
		DFITCCompareFlagType            compareFlag;        //�Ƚϱ�־
		DFITCPriceType                  comparePrice;       //�����۸�
		DFITCPriceReferenceType         priceReference;     //�۸����
		DFITCBreakDownTimesType         breakDownTimes;     //��������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   validate;           //��Ч����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   modifiedtime;       //�޸�ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   commTime;           //ί��ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   commdate;           //ί������
		DFITCSPDOrderIDType             spdOrderID;         //��̨ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   canceledTime;       //����ʱ��
		DFITCFrozenTypeType             frozentype;         //��������
		DFITCSPDOrderIDType             extSpdOrderID;      //���������
		DFITCExtOrderType               extOrderType;       //����������
		DFITCProfitLossType             frozenMargin;       //�����ʽ�
		DFITCAmountType                 frozenAmount;       //��������
		DFITCOrderAnswerStatusType      orderStatus;        //ί��״̬
		DFITCExtOrderTriggerStatusType  orderTriggerStatus; //����������״̬
		DFITCAmountType                 limitAmount;        //��������
		DFITCCompareFlagType            qtyCmpFlag;         //�Ƚϱ�־(����)
		DFITCTriggerType                triggerType;        //��������	
		DFITCBreakDownTypeType          breakDownType;      //��������	

	};



	///��ѯ�ɽ�����ί��
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryMatchTriggerField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //�ʽ��˻�
		DFITCRequestIDType              lRequestID;         //����ID
		DFITCLocalOrderIDType           localOrderID;       //����ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID;       //��Լ����
		DFITCBuySellTypeType            buySellType;        //������־
		DFITCOpenCloseTypeType          openCloseType;      //��ƽ��־
		DFITCSpeculatorType             speculator;         //Ͷ������
		DFITCPriceType                  insertPrice;        //ί�м۸�
		DFITCAmountType                 orderAmount;        //ί������
		DFITCAmountType                 matchedAmount;      //�ɽ�����
		DFITCAmountType                 cancelAmount;       //��������
		DFITCSPDOrderIDType             spdOrderID;         //��̨ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           trigInstrumentID;   //��Լ����
		DFITCBuySellTypeType            trigBuySellType;    //������־
		DFITCOpenCloseTypeType          trigOpenCloseType;  //��ƽ��־
		DFITCSpeculatorType             trigSpeculator;     //Ͷ������
		DFITCPriceType                  trigInsertPrice;    //ί�м۸�
		DFITCAmountType                 trigOrderAmount;    //ί������ 
		DFITCSPDOrderIDType             trigSpdOrderID;     //��̨ί�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   commdate;           //ί������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   commTime;           //ί��ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   canceledTime;       //����ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   modifiedtime;       //�޸�ʱ��
		DFITCOrderTypeType              orderType;          //��������
		DFITCProfitLossType             frozenMargin;       //�����ʽ�
		DFITCAmountType                 frozenAmount;       //��������
		DFITCCompareFlagType            compareFlag;        //�Ƚϱ�־
		DFITCPriceType                  comparePrice;       //�����۸�
		DFITCPriceReferenceType         priceReference;     //�۸����
		DFITCBreakDownTimesType         breakDownTimes;     //��������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   validate;           //��Ч����
		DFITCSPDOrderIDType             trigExtSpdOrderID;  //���������
		DFITCExtOrderType               extOrderType;       //����������
		DFITCOrderAnswerStatusType      orderStatus;        //ί��״̬
	};

	///��ѯֹ��ֹӯ����ί��
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCProfitLossRspField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //�ʽ��˻�
		DFITCRequestIDType              lRequestID;         //����ID 
		DFITCLocalOrderIDType           localOrderID;       //����ί�к�
		DFITCSPDOrderIDType             spdOrderID;         //��̨ί�к�
		DFITCSPDOrderIDType             trigSpdOrderID;     //��̨ί�к�
		DFITCSPDOrderIDType             trigExtSpdOrderID;  //���������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID;       //��Լ����
		DFITCPriceType                  insertPrice;        //ί�м۸�
		DFITCAmountType                 orderAmount;        //ί������
		DFITCSpeculatorType             speculator;         //Ͷ������
		DFITCBuySellTypeType            buySellType;        //������־
		DFITCOpenCloseTypeType          openCloseType;      //��ƽ��־
		DFITCPriceType                  comparePriceFall;   //�µ������۲�
		DFITCPriceType                  insertPriceFall;    //�µ�ί�м۲�
		DFITCAddPriceTimesType          addPriceTimesFall;  //�µ�׷�۴���
		DFITCOrderTypeType              orderTypeFall;      //�µ���������
		DFITCPriceType                  comparePriceRise;   //���Ǵ����۲�
		DFITCPriceType                  insertPriceRise;    //����ί�м۲�
		DFITCAddPriceTimesType          addPriceTimesRise;  //����׷�۴���
		DFITCOrderTypeType              orderTypeRise;      //���Ǳ�������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   validate;           //��Ч����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   commTime;           //ί��ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   canceledTime;       //����ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   modifiedtime;       //�޸�ʱ��
		DFITCOrderAnswerStatusType      orderStatus;        //ί��״̬
	};

	///��ѯ������������ί��
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCArbitrageRspField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //�ʽ��˻�
		DFITCRequestIDType              lRequestID;         //����ID 
		DFITCLocalOrderIDType           localOrderID;       //����ί�к�
		DFITCSPDOrderIDType             extSpdOrderID;      //���������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID;       //��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID2;      //��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID3;      //��Լ����
		DFITCPriceType                  insertPrice;        //ƫ����
		DFITCAmountType                 orderAmount;        //ί������
		DFITCSpeculatorType             speculator;         //Ͷ������
		DFITCBuySellTypeType            buySellType;        //������־
		DFITCOpenCloseTypeType          openCloseType;      //��ƽ��־
		DFITCPriceType                  insertPrice2;       //ƫ����2
		DFITCAmountType                 orderAmount2;       //ί������2
		DFITCSpeculatorType             speculator2;        //Ͷ������2
		DFITCBuySellTypeType            buySellType2;       //������־2
		DFITCOpenCloseTypeType          openCloseType2;     //��ƽ��־2
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   modifiedtime;       //�޸�ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   commTime;           //ί��ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   commdate;           //ί������
		DFITCPriceType                  priceMargin;        //�۲�
		DFITCArbitrageTypeType          arbitrageType;      //��������
		DFITCMinEntryType               minEntry;           //��С��������
		DFITCSplitContinueType          splitContinue;      //�����Ƿ����
		DFITCPriceType                  deviatePrice;       //ƫ����
		DFITCOrderAnswerStatusType      orderStatus;        //ί��״̬
	};


	///������ί����Ӧ����
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCExtOrderRspDataField
	{
		DFITCLocalOrderIDType           localOrderID;       //����ί�к�
		DFITCSPDOrderIDType             spdOrderID;         //��̨ί�к�
		DFITCSPDOrderIDType             extSpdOrderID;      //���������
		DFITCOrderAnswerStatusType      orderStatus;        //ί��״̬
		DFITCRequestIDType              lRequestID;         //����ID
		DFITCPriceType                  frozenMargin;       //�����ʽ�(���µ�ʹ��)
		DFITCExtOrderType               extOrderType;       //����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //�ʽ��˻�
	};
}