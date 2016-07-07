// CLRXspeedApi.h

#pragma once
#pragma comment(lib,"DFITCMdApi.lib")
#pragma comment(lib,"DFITCTraderApi.lib")

#pragma managed

#include <stdio.h>
#include <windows.h>
#include <string>
#include <gcroot.h>
#include <msclr/auto_gcroot.h>
#include "DFITCTraderApi.h"
#include "DFITCMdApi.h"
#include "CLRDFITCApiDataStruct.h"

using namespace System;
using namespace Collections;
using namespace Threading;
using namespace Tasks;
using namespace Runtime::InteropServices;

namespace CLRXspeedApi {

	public ref class CLRDFITCTraderSpi abstract
	{
	public:
		CLRDFITCTraderSpi();
		~CLRDFITCTraderSpi();
		DFITCXSPEEDAPI::DFITCTraderSpi* m_pNativeSpi;
	protected:
		/* ��������������Ӧ:���ͻ����뽻�׺�̨�轨����ͨ������ʱ����δ��¼ǰ�����ͻ���API���Զ������ǰ�û�֮������ӣ�
		* ��������ã����Զ��������ӣ������ø÷���֪ͨ�ͻ��ˣ� �ͻ��˿�����ʵ�ָ÷���ʱ������ʹ���ʽ��˺Ž��е�¼��
		*���÷�������Api��ǰ�û��������Ӻ󱻵��ã��õ��ý�����˵��tcp�����Ѿ������ɹ����û���Ҫ���е�¼���ܽ��к�����ҵ�������
		*  ��¼ʧ����˷������ᱻ���á���
		*/
		virtual void OnFrontConnected() = 0;

		/**
		* �������Ӳ�������Ӧ�����ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
		* @param  nReason:����ԭ��
		*        0x1001 �����ʧ��
		*        0x1002 ����дʧ��
		*        0x2001 ����������ʱ
		*        0x2002 ��������ʧ��
		*        0x2003 �յ�������
		*/
		virtual void OnFrontDisconnected(int nReason) = 0;

		/**
		* ��½������Ӧ:���û�������¼�����ǰ�û�������Ӧʱ�˷����ᱻ���ã�֪ͨ�û���¼�Ƿ�ɹ���
		* @param pUserLoginInfoRtn:�û���¼��Ϣ�ṹ��ַ��
		* @param pErrorInfo:����¼ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspUserLogin(CLRDFITCUserLoginInfoRtnField  RspUserLogin, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* �ǳ�������Ӧ:���û������˳������ǰ�û�������Ӧ�˷����ᱻ���ã�֪ͨ�û��˳�״̬��
		* @param pUserLogoutInfoRtn:�����û��˳���Ϣ�ṹ��ַ��
		* @param pErrorInfo:���ǳ�ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspUserLogout(CLRDFITCUserLogoutInfoRtnField  RspUserLogout, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* �ڻ�ί�б�����Ӧ:���û�¼�뱨����ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pOrderRtn:�����û��µ���Ϣ�ṹ��ַ��
		* @param pErrorInfo:������ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspInsertOrder(CLRDFITCOrderRspDataRtnField  RspOrder, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* �ڻ�ί�г�����Ӧ:���û�������ǰ�÷�����Ӧ�Ǹ÷����ᱻ���á�
		* @param pOrderCanceledRtn:���س�����Ӧ��Ϣ�ṹ��ַ��
		* @param pErrorInfo:������ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspCancelOrder(CLRDFITCOrderRspDataRtnField  RspOrderCancel, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* ����ر�
		* @param pErrorInfo:������Ϣ�Ľṹ��ַ��
		*/
		virtual void OnRtnErrorMsg(CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* �ɽ��ر�:��ί�гɹ����׺�˷����ᱻ���á�
		* @param pRtnMatchData:ָ��ɽ��ر��Ľṹ��ָ�롣
		*/
		virtual void OnRtnMatchedInfo(CLRDFITCMatchRtnField  RtnMatchData) = 0;

		/**
		* ί�лر�:�µ�ί�гɹ��󣬴˷����ᱻ���á�
		* @param pRtnOrderData:ָ��ί�лر���ַ��ָ�롣
		*/
		virtual void OnRtnOrder(CLRDFITCOrderRtnField  RtnOrderData) = 0;

		/**
		* �����ر�:�������ɹ���÷����ᱻ���á�
		* @param pCancelOrderData:ָ�򳷵��ر��ṹ�ĵ�ַ���ýṹ�������������Լ�������Ϣ��
		*/
		virtual void OnRtnCancelOrder(CLRDFITCOrderCanceledRtnField  RtnCancelOrderData) = 0;

		/**
		* ��ѯ����ί����Ӧ:���û�����ί�в�ѯ�󣬸÷����ᱻ���á�
		* @param pRtnOrderData:ָ��ί�лر��ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryOrderInfo(CLRDFITCOrderCommRtnField  OrderData, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* ��ѯ���ճɽ���Ӧ:���û������ɽ���ѯ��÷����ᱻ���á�
		* @param pRtnMatchData:ָ��ɽ��ر��ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryMatchInfo(CLRDFITCMatchedRtnField  MatchData, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* �ֲֲ�ѯ��Ӧ:���û������ֲֲ�ѯָ���ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pPositionInfoRtn:���سֲ���Ϣ�ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryPosition(CLRDFITCPositionInfoRtnField  PositionInfo, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* �ͻ��ʽ��ѯ��Ӧ:���û������ʽ��ѯָ���ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pCapitalInfoRtn:�����ʽ���Ϣ�ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspCustomerCapital(CLRDFITCCapitalInfoRtnField  CapitalInfo, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* ��������Լ��ѯ��Ӧ:���û�������Լ��ѯָ���ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pInstrumentData:���غ�Լ��Ϣ�ṹ�ĵ�ַ��
		* @param pErrorInfo:������Ϣ�ṹ�������ѯ���������򷵻ش�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryExchangeInstrument(CLRDFITCExchangeInstrumentRtnField  InstrumentData, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* ������Լ��ѯ��Ӧ:���û�����������Լ��ѯָ���ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pAbiInstrumentData:����������Լ��Ϣ�ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspArbitrageInstrument(CLRDFITCAbiInstrumentRtnField  AbiInstrumentData, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* ��ѯָ����Լ��Ӧ:���û�����ָ����Լ��ѯָ���ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pInstrument:����ָ����Լ��Ϣ�ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQrySpecifyInstrument(CLRDFITCInstrumentRtnField  Instrument, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* ��ѯ�ֲ���ϸ��Ӧ:���û�������ѯ�ֲ���ϸ��ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pPositionDetailRtn:���سֲ���ϸ�ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryPositionDetail(CLRDFITCPositionDetailRtnField  PositionDetail, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* ����֪ͨ��Ӧ:���ڽ���XSPEED��̨�ֶ�����֪ͨ����֧��ָ���ͻ���Ҳ֧��ϵͳ�㲥��
		* @param pTradingNoticeInfo: �����û��¼�֪ͨ�ṹ�ĵ�ַ��
		*/
		virtual void OnRtnTradingNotice(CLRDFITCTradingNoticeInfoField  TradingNoticeInfo) = 0;

		/**
		* �����޸���Ӧ:�����޸��ʽ��˻���¼���롣
		* @param pResetPassword: ���������޸Ľṹ�ĵ�ַ��
		* @param pErrorInfo:���޸�����ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspResetPassword(CLRDFITCResetPwdRspField  ResetPassword, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* ���ױ����ѯ��Ӧ:���ؽ��ױ�����Ϣ
		* @param pTradeCode: ���ؽ��ױ����ѯ�ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryTradeCode(CLRDFITCQryTradeCodeRtnField  TradeCode, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* �˵�ȷ����Ӧ:���ڽ��տͻ��˵�ȷ��״̬��
		* @param pBillConfirm: �����˵�ȷ�Ͻṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspBillConfirm(CLRDFITCBillConfirmRspField  BillConfirm, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* ��ѯ�ͻ�Ȩ����㷽ʽ��Ӧ:���ؿͻ�Ȩ�����ķ�ʽ
		* @param pEquityComputMode: ���ؿͻ�Ȩ����㷽ʽ�ṹ�ĵ�ַ��
		*/
		virtual void OnRspEquityComputMode(CLRDFITCEquityComputModeRtnField  EquityComputMode) = 0;

		/**
		* �ͻ������˵���ѯ��Ӧ:�����˵���Ϣ
		* @param pQryBill: ���ؿͻ������˵���ѯ�ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryBill(CLRDFITCQryBillRtnField QryBill, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* ����IDȷ����Ӧ:���ڽ��ճ�����Ϣ��
		* @param pProductRtnData: ���س���IDȷ����Ӧ�ṹ�ĵ�ַ��
		*/
		virtual void OnRspConfirmProductInfo(CLRDFITCProductRtnField  RspProductData) = 0;


		/**
		* ������ȷ����Ӧ:���ڽ��ս�������Ϣ��
		* @param DFITCTradingDayRtnField: ���ؽ���������ȷ����Ӧ�ṹ�ĵ�ַ��
		*/
		virtual void OnRspTradingDay(CLRDFITCTradingDayRtnField  TradingDayRtnData) = 0;

		/**
		* �����̱�����Ӧ
		* @param pRspQuoteData:ָ�������̱�����Ӧ��ַ��ָ�롣
		* @param pErrorInfo:������ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspQuoteInsert(CLRDFITCQuoteRspField  RspQuote, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* �����̱����ر�
		* @param pRtnQuoteData:ָ�������̱����ر���ַ��ָ�롣
		*/
		virtual void OnRtnQuoteInsert(CLRDFITCQuoteRtnField  RtnQuote) = 0;

		/**
		* �����̳�����Ӧ
		* @param pRspQuoteCanceledData:ָ�������̳�����Ӧ��ַ��ָ�롣
		* @param pErrorInfo:������ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspQuoteCancel(CLRDFITCQuoteRspField  RspQuoteCancel, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* �����̳����ر�
		* @param pRtnQuoteCanceledData:ָ�������̳����ر���ַ��ָ�롣
		*/
		virtual void OnRtnQuoteCancel(CLRDFITCQuoteCanceledRtnField  RtnQuoteCanceled) = 0;

		/**
		* �����̳ɽ��ر�
		* @param pRtnQuoteMatchedData:ָ�������̳ɽ��ر���ַ��ָ�롣
		*/
		virtual void OnRtnQuoteMatchedInfo(CLRDFITCQuoteMatchRtnField  RtnQuoteMatched) = 0;

		/**
		* ������ѯ��֪ͨ�����趩�ģ������̿ͻ��Զ��յ�ѯ��֪ͨ
		* @param pForQuoteRspData:ָ��ѯ��֪ͨ�ر���ַ��ָ�롣
		*/
		virtual void OnRtnForQuoteRsp(CLRDFITCQuoteSubscribeRtnField  ForQuoteRspData) = 0;

		/**
		* ����������������Ӧ
		* @param pRspStripCancelOrderData:ָ������������Ӧ��ַ��ָ�롣
		* @param pErrorInfo:����������ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspCancelAllOrder(CLRDFITCCancelAllOrderRspField RspCancelAllOrderData, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* ѯ��֪ͨ��ѯ��Ӧ
		* @param pRtnQryQuoteNoticeData:��ѯѯ��֪ͨ�ر��ṹ��ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryQuoteNotice(CLRDFITCQryQuoteNoticeRtnField  QryQuoteNoticeData, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* ѯ����Ӧ
		* @param pRspForQuoteData:ѯ��������Ӧ�ṹ��ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspForQuote(CLRDFITCForQuoteRspField  RspForQuoteData, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* ѯ�ۻر�
		* @param pRtnForQuoteData:ѯ�ۻر��ṹ��ַ��
		*/
		virtual void OnRtnForQuote(CLRDFITCForQuoteRtnField  RtnForQuote) = 0;

		/**
		* ��ѯ���ձ���ί����Ӧ
		* @param pRtnQuoteOrderData:ָ�򱨼۲�ѯ�ر��ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryQuoteOrderInfo(CLRDFITCQuoteOrderRtnField  QuoteOrderData, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* ѯ��ί�в�ѯ��Ӧ
		* @param pRtnQryForQuoteData:ָ��ѯ��ί�в�ѯ��Ӧ��ַ��ָ�롣
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryForQuote(CLRDFITCQryForQuoteRtnField  QryForQuoteData, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* ��ѯת��������Ӧ
		* @param pTransferBank:ָ���ѯת�����лر���ַ��ָ�롣
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryTransferBank(CLRDFITCTransferBankRspField  TransferBank, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* ��ѯת����ˮ��Ӧ
		* @param pTransferSerial:ָ���ѯת����ˮ�ر���ַ��ָ�롣
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryTransferSerial(CLRDFITCTransferSerialRspField  TransferSerial, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* �ڻ����������ʽ�ת�ڻ�Ӧ��
		* @param pRspTransfer:ָ���ڻ����������ʽ�ת�ڻ�Ӧ���ַ��ָ�롣
		* @param pErrorInfo:��ת��ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspFromBankToFutureByFuture(CLRDFITCTransferRspField  RspTransfer, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* �ڻ������ڻ��ʽ�ת����Ӧ��
		* @param pRspTransfer:ָ���ڻ������ڻ��ʽ�ת����Ӧ���ַ��ָ�롣
		* @param pErrorInfo:��ת��ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspFromFutureToBankByFuture(CLRDFITCTransferRspField  RspTransfer, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* �ڻ����������ʽ�ת�ڻ�֪ͨ
		* @param pRtnTransfer:ָ���ڻ����������ʽ�ת�ڻ�֪ͨ��ַ��ָ�롣
		* @param pErrorInfo:��ת��ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRtnFromBankToFutureByFuture(CLRDFITCTransferRtnField  RtnTransfer, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* �ڻ������ڻ��ʽ�ת����֪ͨ
		* @param pRtnTransfer:ָ���ڻ������ڻ��ʽ�ת����֪ͨ��ַ��ָ�롣
		* @param pErrorInfo:��ת��ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRtnFromFutureToBankByFuture(CLRDFITCTransferRtnField  RtnTransfer, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* ���з�������ڻ�ת����֪ͨ
		* @param pRspRepeal:ָ���ڻ������ڻ��ʽ�ת���г���֪ͨ��ַ��ָ�롣
		*/
		virtual void OnRtnRepealFromFutureToBankByBank(CLRDFITCRepealRtnField  RspRepeal) = 0;

		/**
		* ������״̬��ѯ��Ӧ
		* @param pRspExchangeStatusData:ָ������״̬��ѯ��Ӧ��ַ��ָ�롣
		*/
		virtual void OnRspQryExchangeStatus(CLRDFITCExchangeStatusRspField  RspExchangeStatusData) = 0;

		/**
		* ������״̬֪ͨ
		* @param pRtnExchangeStatusData:ָ������״̬֪ͨ��ַ��ָ�롣
		*/
		virtual void OnRtnExchangeStatus(CLRDFITCExchangeStatusRtnField  RtnExchangeStatusData) = 0;

		/**
		* �����ѯ��Ӧ
		* @param pDepthMarketData:ָ�������ѯ��Ӧ��ַ��ָ�롣
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryDepthMarketData(CLRDFITCDepthMarketDataField  DepthMarketData, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* ���ʲ�ѯ��Ӧ
		* @param pExchangeRate:ָ����ʲ�ѯ��Ӧ��ַ��ָ�롣
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryExchangeRate(CLRDFITCExchangeRateField ExchangeRate, CLRDFITCErrorRtnField RspInfo, bool bIsLast) = 0;

		/**
		* ���鴥����ѯ��Ӧ:���û��������鴥����ѯָ���ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pQryPricesTriggerRspData:���������ѯ��Ϣ�ṹ�ĵ�ַ��
		* @param pErrorInfo:������Ϣ�ṹ��������鴥�����������򷵻ش�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryPricesTrigger(CLRDFITCQryPricesTriggerField QryPricesTriggerRspData, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* ������ί�б�����Ӧ:���û�¼�뱨����ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pOrderRsp:�����û��µ���Ϣ�ṹ��ַ��
		* @param pErrorInfo:������ʧ�ܣ����ش�����Ϣ��ַ��
		*/
		virtual void OnRspExtInsertOrder(CLRDFITCExtOrderRspDataField  OrderRsp, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* ������ί�г�����Ӧ:���û�������ǰ�÷�����Ӧ�Ǹ÷����ᱻ���á�
		* @param pOrderCancelRsp:���س�����Ӧ��Ϣ�ṹ��ַ��
		* @param pErrorInfo:������ʧ�ܣ����ش�����Ϣ��ַ��
		*/
		virtual void OnRspExtCancelOrder(CLRDFITCExtOrderRspDataField  OrderCancelRsp, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* ������ί�лر�:���û�¼�뱨������������÷����ᱻ���á�
		* @param pOrderRtn:�����û��µ���Ϣ�ṹ��ַ��
		*/
		virtual void OnRtnPricesTrigger(CLRDFITCPricesTriggerRtnField  OrderRtn) = 0;

	internal:
		/* ��������������Ӧ:���ͻ����뽻�׺�̨�轨����ͨ������ʱ����δ��¼ǰ�����ͻ���API���Զ������ǰ�û�֮������ӣ�
		* ��������ã����Զ��������ӣ������ø÷���֪ͨ�ͻ��ˣ� �ͻ��˿�����ʵ�ָ÷���ʱ������ʹ���ʽ��˺Ž��е�¼��
		*���÷�������Api��ǰ�û��������Ӻ󱻵��ã��õ��ý�����˵��tcp�����Ѿ������ɹ����û���Ҫ���е�¼���ܽ��к�����ҵ�������
		*  ��¼ʧ����˷������ᱻ���á���
		*/
		void callOnFrontConnected();

		/**
		* �������Ӳ�������Ӧ�����ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
		* @param  nReason:����ԭ��
		*        0x1001 �����ʧ��
		*        0x1002 ����дʧ��
		*        0x2001 ����������ʱ
		*        0x2002 ��������ʧ��
		*        0x2003 �յ�������
		*/
		void callOnFrontDisconnected(int nReason);
		/**
		* ��½������Ӧ:���û�������¼�����ǰ�û�������Ӧʱ�˷����ᱻ���ã�֪ͨ�û���¼�Ƿ�ɹ���
		* @param pUserLoginInfoRtn:�û���¼��Ϣ�ṹ��ַ��
		* @param pErrorInfo:����¼ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		void callOnRspUserLogin(struct DFITCUserLoginInfoRtnField * pRspUserLogin, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* �ǳ�������Ӧ:���û������˳������ǰ�û�������Ӧ�˷����ᱻ���ã�֪ͨ�û��˳�״̬��
		* @param pUserLogoutInfoRtn:�����û��˳���Ϣ�ṹ��ַ��
		* @param pErrorInfo:���ǳ�ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		void callOnRspUserLogout(struct DFITCUserLogoutInfoRtnField * pRspUserLogout, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* �ڻ�ί�б�����Ӧ:���û�¼�뱨����ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pOrderRtn:�����û��µ���Ϣ�ṹ��ַ��
		* @param pErrorInfo:������ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		void callOnRspInsertOrder(struct DFITCOrderRspDataRtnField * pRspOrder, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* �ڻ�ί�г�����Ӧ:���û�������ǰ�÷�����Ӧ�Ǹ÷����ᱻ���á�
		* @param pOrderCanceledRtn:���س�����Ӧ��Ϣ�ṹ��ַ��
		* @param pErrorInfo:������ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		void callOnRspCancelOrder(struct DFITCOrderRspDataRtnField * pRspOrderCancel, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* ����ر�
		* @param pErrorInfo:������Ϣ�Ľṹ��ַ��
		*/
		void callOnRtnErrorMsg(struct DFITCErrorRtnField * pErrorInfo);

		/**
		* �ɽ��ر�:��ί�гɹ����׺�˷����ᱻ���á�
		* @param pRtnMatchData:ָ��ɽ��ر��Ľṹ��ָ�롣
		*/
		void callOnRtnMatchedInfo(struct DFITCMatchRtnField * pRtnMatchData);

		/**
		* ί�лر�:�µ�ί�гɹ��󣬴˷����ᱻ���á�
		* @param pRtnOrderData:ָ��ί�лر���ַ��ָ�롣
		*/
		void callOnRtnOrder(struct DFITCOrderRtnField * pRtnOrderData);

		/**
		* �����ر�:�������ɹ���÷����ᱻ���á�
		* @param pCancelOrderData:ָ�򳷵��ر��ṹ�ĵ�ַ���ýṹ�������������Լ�������Ϣ��
		*/
		void callOnRtnCancelOrder(struct DFITCOrderCanceledRtnField * pRtnCancelOrderData);

		/**
		* ��ѯ����ί����Ӧ:���û�����ί�в�ѯ�󣬸÷����ᱻ���á�
		* @param pRtnOrderData:ָ��ί�лر��ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		void callOnRspQryOrderInfo(struct DFITCOrderCommRtnField * pOrderData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* ��ѯ���ճɽ���Ӧ:���û������ɽ���ѯ��÷����ᱻ���á�
		* @param pRtnMatchData:ָ��ɽ��ر��ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		void callOnRspQryMatchInfo(struct DFITCMatchedRtnField * pMatchData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* �ֲֲ�ѯ��Ӧ:���û������ֲֲ�ѯָ���ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pPositionInfoRtn:���سֲ���Ϣ�ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		void callOnRspQryPosition(struct DFITCPositionInfoRtnField * pPositionInfo, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* �ͻ��ʽ��ѯ��Ӧ:���û������ʽ��ѯָ���ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pCapitalInfoRtn:�����ʽ���Ϣ�ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		void callOnRspCustomerCapital(struct DFITCCapitalInfoRtnField * pCapitalInfo, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* ��������Լ��ѯ��Ӧ:���û�������Լ��ѯָ���ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pInstrumentData:���غ�Լ��Ϣ�ṹ�ĵ�ַ��
		* @param pErrorInfo:������Ϣ�ṹ�������ѯ���������򷵻ش�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		void callOnRspQryExchangeInstrument(struct DFITCExchangeInstrumentRtnField * pInstrumentData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* ������Լ��ѯ��Ӧ:���û�����������Լ��ѯָ���ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pAbiInstrumentData:����������Լ��Ϣ�ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		void callOnRspArbitrageInstrument(struct DFITCAbiInstrumentRtnField * pAbiInstrumentData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* ��ѯָ����Լ��Ӧ:���û�����ָ����Լ��ѯָ���ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pInstrument:����ָ����Լ��Ϣ�ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		void callOnRspQrySpecifyInstrument(struct DFITCInstrumentRtnField * pInstrument, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* ��ѯ�ֲ���ϸ��Ӧ:���û�������ѯ�ֲ���ϸ��ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pPositionDetailRtn:���سֲ���ϸ�ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		void callOnRspQryPositionDetail(struct DFITCPositionDetailRtnField * pPositionDetail, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* ����֪ͨ��Ӧ:���ڽ���XSPEED��̨�ֶ�����֪ͨ����֧��ָ���ͻ���Ҳ֧��ϵͳ�㲥��
		* @param pTradingNoticeInfo: �����û��¼�֪ͨ�ṹ�ĵ�ַ��
		*/
		void callOnRtnTradingNotice(struct DFITCTradingNoticeInfoField * pTradingNoticeInfo);

		/**
		* �����޸���Ӧ:�����޸��ʽ��˻���¼���롣
		* @param pResetPassword: ���������޸Ľṹ�ĵ�ַ��
		* @param pErrorInfo:���޸�����ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		void callOnRspResetPassword(struct DFITCResetPwdRspField * pResetPassword, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* ���ױ����ѯ��Ӧ:���ؽ��ױ�����Ϣ
		* @param pTradeCode: ���ؽ��ױ����ѯ�ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		void callOnRspQryTradeCode(struct DFITCQryTradeCodeRtnField * pTradeCode, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* �˵�ȷ����Ӧ:���ڽ��տͻ��˵�ȷ��״̬��
		* @param pBillConfirm: �����˵�ȷ�Ͻṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		void callOnRspBillConfirm(struct DFITCBillConfirmRspField * pBillConfirm, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* ��ѯ�ͻ�Ȩ����㷽ʽ��Ӧ:���ؿͻ�Ȩ�����ķ�ʽ
		* @param pEquityComputMode: ���ؿͻ�Ȩ����㷽ʽ�ṹ�ĵ�ַ��
		*/
		void callOnRspEquityComputMode(struct DFITCEquityComputModeRtnField * pEquityComputMode);

		/**
		* �ͻ������˵���ѯ��Ӧ:�����˵���Ϣ
		* @param pQryBill: ���ؿͻ������˵���ѯ�ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		void callOnRspQryBill(struct DFITCQryBillRtnField *pQryBill, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* ����IDȷ����Ӧ:���ڽ��ճ�����Ϣ��
		* @param pProductRtnData: ���س���IDȷ����Ӧ�ṹ�ĵ�ַ��
		*/
		void callOnRspConfirmProductInfo(struct DFITCProductRtnField * pRspProductData);


		/**
		* ������ȷ����Ӧ:���ڽ��ս�������Ϣ��
		* @param DFITCTradingDayRtnField: ���ؽ���������ȷ����Ӧ�ṹ�ĵ�ַ��
		*/
		void callOnRspTradingDay(struct DFITCTradingDayRtnField * pTradingDayRtnData);

		/**
		* �����̱�����Ӧ
		* @param pRspQuoteData:ָ�������̱�����Ӧ��ַ��ָ�롣
		* @param pErrorInfo:������ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		void callOnRspQuoteInsert(struct DFITCQuoteRspField * pRspQuote, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* �����̱����ر�
		* @param pRtnQuoteData:ָ�������̱����ر���ַ��ָ�롣
		*/
		void callOnRtnQuoteInsert(struct DFITCQuoteRtnField * pRtnQuote);

		/**
		* �����̳�����Ӧ
		* @param pRspQuoteCanceledData:ָ�������̳�����Ӧ��ַ��ָ�롣
		* @param pErrorInfo:������ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		void callOnRspQuoteCancel(struct DFITCQuoteRspField * pRspQuoteCancel, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* �����̳����ر�
		* @param pRtnQuoteCanceledData:ָ�������̳����ر���ַ��ָ�롣
		*/
		void callOnRtnQuoteCancel(struct DFITCQuoteCanceledRtnField * pRtnQuoteCanceled);

		/**
		* �����̳ɽ��ر�
		* @param pRtnQuoteMatchedData:ָ�������̳ɽ��ر���ַ��ָ�롣
		*/
		void callOnRtnQuoteMatchedInfo(struct DFITCQuoteMatchRtnField * pRtnQuoteMatched);

		/**
		* ������ѯ��֪ͨ�����趩�ģ������̿ͻ��Զ��յ�ѯ��֪ͨ
		* @param pForQuoteRspData:ָ��ѯ��֪ͨ�ر���ַ��ָ�롣
		*/
		void callOnRtnForQuoteRsp(struct DFITCQuoteSubscribeRtnField * pForQuoteRspData);

		/**
		* ����������������Ӧ
		* @param pRspStripCancelOrderData:ָ������������Ӧ��ַ��ָ�롣
		* @param pErrorInfo:����������ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		void callOnRspCancelAllOrder(struct DFITCCancelAllOrderRspField *pRspCancelAllOrderData, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* ѯ��֪ͨ��ѯ��Ӧ
		* @param pRtnQryQuoteNoticeData:��ѯѯ��֪ͨ�ر��ṹ��ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		void callOnRspQryQuoteNotice(struct DFITCQryQuoteNoticeRtnField * pQryQuoteNoticeData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* ѯ����Ӧ
		* @param pRspForQuoteData:ѯ��������Ӧ�ṹ��ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		void callOnRspForQuote(struct DFITCForQuoteRspField * pRspForQuoteData, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* ѯ�ۻر�
		* @param pRtnForQuoteData:ѯ�ۻر��ṹ��ַ��
		*/
		void callOnRtnForQuote(struct DFITCForQuoteRtnField * pRtnForQuote);

		/**
		* ��ѯ���ձ���ί����Ӧ
		* @param pRtnQuoteOrderData:ָ�򱨼۲�ѯ�ر��ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		void callOnRspQryQuoteOrderInfo(struct DFITCQuoteOrderRtnField * pQuoteOrderData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* ѯ��ί�в�ѯ��Ӧ
		* @param pRtnQryForQuoteData:ָ��ѯ��ί�в�ѯ��Ӧ��ַ��ָ�롣
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		void callOnRspQryForQuote(struct DFITCQryForQuoteRtnField * pQryForQuoteData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* ��ѯת��������Ӧ
		* @param pTransferBank:ָ���ѯת�����лر���ַ��ָ�롣
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		void callOnRspQryTransferBank(struct DFITCTransferBankRspField * pTransferBank, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* ��ѯת����ˮ��Ӧ
		* @param pTransferSerial:ָ���ѯת����ˮ�ر���ַ��ָ�롣
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		void callOnRspQryTransferSerial(struct DFITCTransferSerialRspField * pTransferSerial, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* �ڻ����������ʽ�ת�ڻ�Ӧ��
		* @param pRspTransfer:ָ���ڻ����������ʽ�ת�ڻ�Ӧ���ַ��ָ�롣
		* @param pErrorInfo:��ת��ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		void callOnRspFromBankToFutureByFuture(struct DFITCTransferRspField * pRspTransfer, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* �ڻ������ڻ��ʽ�ת����Ӧ��
		* @param pRspTransfer:ָ���ڻ������ڻ��ʽ�ת����Ӧ���ַ��ָ�롣
		* @param pErrorInfo:��ת��ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		void callOnRspFromFutureToBankByFuture(struct DFITCTransferRspField * pRspTransfer, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* �ڻ����������ʽ�ת�ڻ�֪ͨ
		* @param pRtnTransfer:ָ���ڻ����������ʽ�ת�ڻ�֪ͨ��ַ��ָ�롣
		* @param pErrorInfo:��ת��ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		void callOnRtnFromBankToFutureByFuture(DFITCTransferRtnField * pRtnTransfer, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* �ڻ������ڻ��ʽ�ת����֪ͨ
		* @param pRtnTransfer:ָ���ڻ������ڻ��ʽ�ת����֪ͨ��ַ��ָ�롣
		* @param pErrorInfo:��ת��ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		void callOnRtnFromFutureToBankByFuture(DFITCTransferRtnField * pRtnTransfer, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* ���з�������ڻ�ת����֪ͨ
		* @param pRspRepeal:ָ���ڻ������ڻ��ʽ�ת���г���֪ͨ��ַ��ָ�롣
		*/
		void callOnRtnRepealFromFutureToBankByBank(DFITCRepealRtnField * pRspRepeal);

		/**
		* ������״̬��ѯ��Ӧ
		* @param pRspExchangeStatusData:ָ������״̬��ѯ��Ӧ��ַ��ָ�롣
		*/
		void callOnRspQryExchangeStatus(struct DFITCExchangeStatusRspField * pRspExchangeStatusData);

		/**
		* ������״̬֪ͨ
		* @param pRtnExchangeStatusData:ָ������״̬֪ͨ��ַ��ָ�롣
		*/
		void callOnRtnExchangeStatus(struct DFITCExchangeStatusRtnField * pRtnExchangeStatusData);

		/**
		* �����ѯ��Ӧ
		* @param pDepthMarketData:ָ�������ѯ��Ӧ��ַ��ָ�롣
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		void callOnRspQryDepthMarketData(struct DFITCDepthMarketDataField * pDepthMarketData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* ���ʲ�ѯ��Ӧ
		* @param pExchangeRate:ָ����ʲ�ѯ��Ӧ��ַ��ָ�롣
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		void callOnRspQryExchangeRate(struct DFITCExchangeRateField *pExchangeRate, DFITCErrorRtnField *pRspInfo, bool bIsLast);

		/**
		* ���鴥����ѯ��Ӧ:���û��������鴥����ѯָ���ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pQryPricesTriggerRspData:���������ѯ��Ϣ�ṹ�ĵ�ַ��
		* @param pErrorInfo:������Ϣ�ṹ��������鴥�����������򷵻ش�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		void callOnRspQryPricesTrigger(struct DFITCQryPricesTriggerField  *pQryPricesTriggerRspData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* ������ί�б�����Ӧ:���û�¼�뱨����ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pOrderRsp:�����û��µ���Ϣ�ṹ��ַ��
		* @param pErrorInfo:������ʧ�ܣ����ش�����Ϣ��ַ��
		*/
		void callOnRspExtInsertOrder(struct DFITCExtOrderRspDataField * pOrderRsp, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* ������ί�г�����Ӧ:���û�������ǰ�÷�����Ӧ�Ǹ÷����ᱻ���á�
		* @param pOrderCancelRsp:���س�����Ӧ��Ϣ�ṹ��ַ��
		* @param pErrorInfo:������ʧ�ܣ����ش�����Ϣ��ַ��
		*/
		void callOnRspExtCancelOrder(struct DFITCExtOrderRspDataField * pOrderCancelRsp, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* ������ί�лر�:���û�¼�뱨������������÷����ᱻ���á�
		* @param pOrderRtn:�����û��µ���Ϣ�ṹ��ַ��
		*/
		void callOnRtnPricesTrigger(struct DFITCPricesTriggerRtnField * pOrderRtn);
	};

	class TradeSpiHandler : public DFITCXSPEEDAPI::DFITCTraderSpi
	{
	public:
		TradeSpiHandler(CLRDFITCTraderSpi ^owner) : m_owner(owner) {};
		~TradeSpiHandler() {};
		gcroot<CLRDFITCTraderSpi^> m_owner;
	public:
		/* ��������������Ӧ:���ͻ����뽻�׺�̨�轨����ͨ������ʱ����δ��¼ǰ�����ͻ���API���Զ������ǰ�û�֮������ӣ�
		* ��������ã����Զ��������ӣ������ø÷���֪ͨ�ͻ��ˣ� �ͻ��˿�����ʵ�ָ÷���ʱ������ʹ���ʽ��˺Ž��е�¼��
		*���÷�������Api��ǰ�û��������Ӻ󱻵��ã��õ��ý�����˵��tcp�����Ѿ������ɹ����û���Ҫ���е�¼���ܽ��к�����ҵ�������
		*  ��¼ʧ����˷������ᱻ���á���
		*/
		virtual void OnFrontConnected() 
		{ 
			m_owner->callOnFrontConnected(); 
		}

		/**
		* �������Ӳ�������Ӧ�����ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
		* @param  nReason:����ԭ��
		*        0x1001 �����ʧ��
		*        0x1002 ����дʧ��
		*        0x2001 ����������ʱ
		*        0x2002 ��������ʧ��
		*        0x2003 �յ�������
		*/
		virtual void OnFrontDisconnected(int nReason) 
		{ 
			m_owner->callOnFrontDisconnected(nReason); 
		}
		/**
		* ��½������Ӧ:���û�������¼�����ǰ�û�������Ӧʱ�˷����ᱻ���ã�֪ͨ�û���¼�Ƿ�ɹ���
		* @param pUserLoginInfoRtn:�û���¼��Ϣ�ṹ��ַ��
		* @param pErrorInfo:����¼ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspUserLogin(struct DFITCUserLoginInfoRtnField * pRspUserLogin, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspUserLogin(pRspUserLogin, pErrorInfo);
		}

		/**
		* �ǳ�������Ӧ:���û������˳������ǰ�û�������Ӧ�˷����ᱻ���ã�֪ͨ�û��˳�״̬��
		* @param pUserLogoutInfoRtn:�����û��˳���Ϣ�ṹ��ַ��
		* @param pErrorInfo:���ǳ�ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspUserLogout(struct DFITCUserLogoutInfoRtnField * pRspUserLogout, struct DFITCErrorRtnField * pErrorInfo) 
		{ 
			m_owner->callOnRspUserLogout(pRspUserLogout, pErrorInfo); 
		}

		/**
		* �ڻ�ί�б�����Ӧ:���û�¼�뱨����ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pOrderRtn:�����û��µ���Ϣ�ṹ��ַ��
		* @param pErrorInfo:������ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspInsertOrder(struct DFITCOrderRspDataRtnField * pRspOrder, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspInsertOrder(pRspOrder, pErrorInfo);
		}

		/**
		* �ڻ�ί�г�����Ӧ:���û�������ǰ�÷�����Ӧ�Ǹ÷����ᱻ���á�
		* @param pOrderCanceledRtn:���س�����Ӧ��Ϣ�ṹ��ַ��
		* @param pErrorInfo:������ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspCancelOrder(struct DFITCOrderRspDataRtnField * pRspOrderCancel, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspCancelOrder(pRspOrderCancel, pErrorInfo);
		}

		/**
		* ����ر�
		* @param pErrorInfo:������Ϣ�Ľṹ��ַ��
		*/
		virtual void OnRtnErrorMsg(struct DFITCErrorRtnField * pErrorInfo) { m_owner->callOnRtnErrorMsg(pErrorInfo); }

		/**
		* �ɽ��ر�:��ί�гɹ����׺�˷����ᱻ���á�
		* @param pRtnMatchData:ָ��ɽ��ر��Ľṹ��ָ�롣
		*/
		virtual void OnRtnMatchedInfo(struct DFITCMatchRtnField * pRtnMatchData) { m_owner->callOnRtnMatchedInfo(pRtnMatchData); }

		/**
		* ί�лر�:�µ�ί�гɹ��󣬴˷����ᱻ���á�
		* @param pRtnOrderData:ָ��ί�лر���ַ��ָ�롣
		*/
		virtual void OnRtnOrder(struct DFITCOrderRtnField * pRtnOrderData) { m_owner->callOnRtnOrder(pRtnOrderData); }

		/**
		* �����ر�:�������ɹ���÷����ᱻ���á�
		* @param pCancelOrderData:ָ�򳷵��ر��ṹ�ĵ�ַ���ýṹ�������������Լ�������Ϣ��
		*/
		virtual void OnRtnCancelOrder(struct DFITCOrderCanceledRtnField * pRtnCancelOrderData) 
		{ 
			m_owner->callOnRtnCancelOrder(pRtnCancelOrderData); 
		}

		/**
		* ��ѯ����ί����Ӧ:���û�����ί�в�ѯ�󣬸÷����ᱻ���á�
		* @param pRtnOrderData:ָ��ί�лر��ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryOrderInfo(struct DFITCOrderCommRtnField * pOrderData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryOrderInfo(pOrderData, pErrorInfo, bIsLast);
		}

		/**
		* ��ѯ���ճɽ���Ӧ:���û������ɽ���ѯ��÷����ᱻ���á�
		* @param pRtnMatchData:ָ��ɽ��ر��ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryMatchInfo(struct DFITCMatchedRtnField * pMatchData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryMatchInfo(pMatchData, pErrorInfo, bIsLast);
		}

		/**
		* �ֲֲ�ѯ��Ӧ:���û������ֲֲ�ѯָ���ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pPositionInfoRtn:���سֲ���Ϣ�ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryPosition(struct DFITCPositionInfoRtnField * pPositionInfo, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryPosition(pPositionInfo, pErrorInfo, bIsLast);
		}

		/**
		* �ͻ��ʽ��ѯ��Ӧ:���û������ʽ��ѯָ���ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pCapitalInfoRtn:�����ʽ���Ϣ�ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspCustomerCapital(struct DFITCCapitalInfoRtnField * pCapitalInfo, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspCustomerCapital(pCapitalInfo, pErrorInfo, bIsLast);
		}

		/**
		* ��������Լ��ѯ��Ӧ:���û�������Լ��ѯָ���ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pInstrumentData:���غ�Լ��Ϣ�ṹ�ĵ�ַ��
		* @param pErrorInfo:������Ϣ�ṹ�������ѯ���������򷵻ش�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryExchangeInstrument(struct DFITCExchangeInstrumentRtnField * pInstrumentData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryExchangeInstrument(pInstrumentData, pErrorInfo, bIsLast);
		}

		/**
		* ������Լ��ѯ��Ӧ:���û�����������Լ��ѯָ���ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pAbiInstrumentData:����������Լ��Ϣ�ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspArbitrageInstrument(struct DFITCAbiInstrumentRtnField * pAbiInstrumentData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspArbitrageInstrument(pAbiInstrumentData, pErrorInfo, bIsLast);
		}

		/**
		* ��ѯָ����Լ��Ӧ:���û�����ָ����Լ��ѯָ���ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pInstrument:����ָ����Լ��Ϣ�ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQrySpecifyInstrument(struct DFITCInstrumentRtnField * pInstrument, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQrySpecifyInstrument(pInstrument, pErrorInfo, bIsLast);
		}

		/**
		* ��ѯ�ֲ���ϸ��Ӧ:���û�������ѯ�ֲ���ϸ��ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pPositionDetailRtn:���سֲ���ϸ�ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryPositionDetail(struct DFITCPositionDetailRtnField * pPositionDetail, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryPositionDetail(pPositionDetail, pErrorInfo, bIsLast);
		}

		/**
		* ����֪ͨ��Ӧ:���ڽ���XSPEED��̨�ֶ�����֪ͨ����֧��ָ���ͻ���Ҳ֧��ϵͳ�㲥��
		* @param pTradingNoticeInfo: �����û��¼�֪ͨ�ṹ�ĵ�ַ��
		*/
		virtual void OnRtnTradingNotice(struct DFITCTradingNoticeInfoField * pTradingNoticeInfo) 
		{ 
			m_owner->callOnRtnTradingNotice(pTradingNoticeInfo); 
		}

		/**
		* �����޸���Ӧ:�����޸��ʽ��˻���¼���롣
		* @param pResetPassword: ���������޸Ľṹ�ĵ�ַ��
		* @param pErrorInfo:���޸�����ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspResetPassword(struct DFITCResetPwdRspField * pResetPassword, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspResetPassword(pResetPassword, pErrorInfo);
		}

		/**
		* ���ױ����ѯ��Ӧ:���ؽ��ױ�����Ϣ
		* @param pTradeCode: ���ؽ��ױ����ѯ�ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryTradeCode(struct DFITCQryTradeCodeRtnField * pTradeCode, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryTradeCode(pTradeCode, pErrorInfo, bIsLast);
		}

		/**
		* �˵�ȷ����Ӧ:���ڽ��տͻ��˵�ȷ��״̬��
		* @param pBillConfirm: �����˵�ȷ�Ͻṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspBillConfirm(struct DFITCBillConfirmRspField * pBillConfirm, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspBillConfirm(pBillConfirm, pErrorInfo);
		}

		/**
		* ��ѯ�ͻ�Ȩ����㷽ʽ��Ӧ:���ؿͻ�Ȩ�����ķ�ʽ
		* @param pEquityComputMode: ���ؿͻ�Ȩ����㷽ʽ�ṹ�ĵ�ַ��
		*/
		virtual void OnRspEquityComputMode(struct DFITCEquityComputModeRtnField * pEquityComputMode) 
		{
			m_owner->callOnRspEquityComputMode(pEquityComputMode);
		}

		/**
		* �ͻ������˵���ѯ��Ӧ:�����˵���Ϣ
		* @param pQryBill: ���ؿͻ������˵���ѯ�ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryBill(struct DFITCQryBillRtnField *pQryBill, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryBill(pQryBill, pErrorInfo, bIsLast);
		}

		/**
		* ����IDȷ����Ӧ:���ڽ��ճ�����Ϣ��
		* @param pProductRtnData: ���س���IDȷ����Ӧ�ṹ�ĵ�ַ��
		*/
		virtual void OnRspConfirmProductInfo(struct DFITCProductRtnField * pRspProductData) 
		{
			m_owner->callOnRspConfirmProductInfo(pRspProductData);
		}


		/**
		* ������ȷ����Ӧ:���ڽ��ս�������Ϣ��
		* @param DFITCTradingDayRtnField: ���ؽ���������ȷ����Ӧ�ṹ�ĵ�ַ��
		*/
		virtual void OnRspTradingDay(struct DFITCTradingDayRtnField * pTradingDayRtnData) 
		{
			m_owner->callOnRspTradingDay(pTradingDayRtnData);
		}

		/**
		* �����̱�����Ӧ
		* @param pRspQuoteData:ָ�������̱�����Ӧ��ַ��ָ�롣
		* @param pErrorInfo:������ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspQuoteInsert(struct DFITCQuoteRspField * pRspQuote, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspQuoteInsert(pRspQuote, pErrorInfo);
		}

		/**
		* �����̱����ر�
		* @param pRtnQuoteData:ָ�������̱����ر���ַ��ָ�롣
		*/
		virtual void OnRtnQuoteInsert(struct DFITCQuoteRtnField * pRtnQuote) 
		{
			m_owner->callOnRtnQuoteInsert(pRtnQuote);
		}

		/**
		* �����̳�����Ӧ
		* @param pRspQuoteCanceledData:ָ�������̳�����Ӧ��ַ��ָ�롣
		* @param pErrorInfo:������ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspQuoteCancel(struct DFITCQuoteRspField * pRspQuoteCancel, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspQuoteCancel(pRspQuoteCancel, pErrorInfo);
		}

		/**
		* �����̳����ر�
		* @param pRtnQuoteCanceledData:ָ�������̳����ر���ַ��ָ�롣
		*/
		virtual void OnRtnQuoteCancel(struct DFITCQuoteCanceledRtnField * pRtnQuoteCanceled) 
		{
			m_owner->callOnRtnQuoteCancel(pRtnQuoteCanceled);
		}

		/**
		* �����̳ɽ��ر�
		* @param pRtnQuoteMatchedData:ָ�������̳ɽ��ر���ַ��ָ�롣
		*/
		virtual void OnRtnQuoteMatchedInfo(struct DFITCQuoteMatchRtnField * pRtnQuoteMatched) 
		{
			m_owner->callOnRtnQuoteMatchedInfo(pRtnQuoteMatched);
		}

		/**
		* ������ѯ��֪ͨ�����趩�ģ������̿ͻ��Զ��յ�ѯ��֪ͨ
		* @param pForQuoteRspData:ָ��ѯ��֪ͨ�ر���ַ��ָ�롣
		*/
		virtual void OnRtnForQuoteRsp(struct DFITCQuoteSubscribeRtnField * pForQuoteRspData) 
		{
			m_owner->callOnRtnForQuoteRsp(pForQuoteRspData);
		}

		/**
		* ����������������Ӧ
		* @param pRspStripCancelOrderData:ָ������������Ӧ��ַ��ָ�롣
		* @param pErrorInfo:����������ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspCancelAllOrder(struct DFITCCancelAllOrderRspField *pRspCancelAllOrderData, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspCancelAllOrder(pRspCancelAllOrderData, pErrorInfo);
		}

		/**
		* ѯ��֪ͨ��ѯ��Ӧ
		* @param pRtnQryQuoteNoticeData:��ѯѯ��֪ͨ�ر��ṹ��ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryQuoteNotice(struct DFITCQryQuoteNoticeRtnField * pQryQuoteNoticeData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryQuoteNotice(pQryQuoteNoticeData, pErrorInfo, bIsLast);
		}

		/**
		* ѯ����Ӧ
		* @param pRspForQuoteData:ѯ��������Ӧ�ṹ��ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspForQuote(struct DFITCForQuoteRspField * pRspForQuoteData, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspForQuote(pRspForQuoteData, pErrorInfo);
		}

		/**
		* ѯ�ۻر�
		* @param pRtnForQuoteData:ѯ�ۻر��ṹ��ַ��
		*/
		virtual void OnRtnForQuote(struct DFITCForQuoteRtnField * pRtnForQuote) 
		{
			m_owner->callOnRtnForQuote(pRtnForQuote);
		}

		/**
		* ��ѯ���ձ���ί����Ӧ
		* @param pRtnQuoteOrderData:ָ�򱨼۲�ѯ�ر��ṹ�ĵ�ַ��
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryQuoteOrderInfo(struct DFITCQuoteOrderRtnField * pQuoteOrderData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryQuoteOrderInfo(pQuoteOrderData, pErrorInfo, bIsLast);
		}

		/**
		* ѯ��ί�в�ѯ��Ӧ
		* @param pRtnQryForQuoteData:ָ��ѯ��ί�в�ѯ��Ӧ��ַ��ָ�롣
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryForQuote(struct DFITCQryForQuoteRtnField * pQryForQuoteData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryForQuote(pQryForQuoteData, pErrorInfo, bIsLast);
		}

		/**
		* ��ѯת��������Ӧ
		* @param pTransferBank:ָ���ѯת�����лر���ַ��ָ�롣
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryTransferBank(struct DFITCTransferBankRspField * pTransferBank, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryTransferBank(pTransferBank, pErrorInfo, bIsLast);
		}

		/**
		* ��ѯת����ˮ��Ӧ
		* @param pTransferSerial:ָ���ѯת����ˮ�ر���ַ��ָ�롣
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryTransferSerial(struct DFITCTransferSerialRspField * pTransferSerial, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryTransferSerial(pTransferSerial, pErrorInfo, bIsLast);
		}

		/**
		* �ڻ����������ʽ�ת�ڻ�Ӧ��
		* @param pRspTransfer:ָ���ڻ����������ʽ�ת�ڻ�Ӧ���ַ��ָ�롣
		* @param pErrorInfo:��ת��ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspFromBankToFutureByFuture(struct DFITCTransferRspField * pRspTransfer, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspFromBankToFutureByFuture(pRspTransfer, pErrorInfo);
		}

		/**
		* �ڻ������ڻ��ʽ�ת����Ӧ��
		* @param pRspTransfer:ָ���ڻ������ڻ��ʽ�ת����Ӧ���ַ��ָ�롣
		* @param pErrorInfo:��ת��ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRspFromFutureToBankByFuture(struct DFITCTransferRspField * pRspTransfer, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspFromFutureToBankByFuture(pRspTransfer, pErrorInfo);
		}

		/**
		* �ڻ����������ʽ�ת�ڻ�֪ͨ
		* @param pRtnTransfer:ָ���ڻ����������ʽ�ת�ڻ�֪ͨ��ַ��ָ�롣
		* @param pErrorInfo:��ת��ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRtnFromBankToFutureByFuture(DFITCTransferRtnField * pRtnTransfer, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRtnFromBankToFutureByFuture(pRtnTransfer, pErrorInfo);
		}

		/**
		* �ڻ������ڻ��ʽ�ת����֪ͨ
		* @param pRtnTransfer:ָ���ڻ������ڻ��ʽ�ת����֪ͨ��ַ��ָ�롣
		* @param pErrorInfo:��ת��ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		*/
		virtual void OnRtnFromFutureToBankByFuture(DFITCTransferRtnField * pRtnTransfer, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRtnFromFutureToBankByFuture(pRtnTransfer, pErrorInfo);
		}

		/**
		* ���з�������ڻ�ת����֪ͨ
		* @param pRspRepeal:ָ���ڻ������ڻ��ʽ�ת���г���֪ͨ��ַ��ָ�롣
		*/
		virtual void OnRtnRepealFromFutureToBankByBank(DFITCRepealRtnField * pRspRepeal) 
		{
			m_owner->callOnRtnRepealFromFutureToBankByBank(pRspRepeal);
		}

		/**
		* ������״̬��ѯ��Ӧ
		* @param pRspExchangeStatusData:ָ������״̬��ѯ��Ӧ��ַ��ָ�롣
		*/
		virtual void OnRspQryExchangeStatus(struct DFITCExchangeStatusRspField * pRspExchangeStatusData) 
		{
			m_owner->callOnRspQryExchangeStatus(pRspExchangeStatusData);
		}

		/**
		* ������״̬֪ͨ
		* @param pRtnExchangeStatusData:ָ������״̬֪ͨ��ַ��ָ�롣
		*/
		virtual void OnRtnExchangeStatus(struct DFITCExchangeStatusRtnField * pRtnExchangeStatusData) 
		{
			m_owner->callOnRtnExchangeStatus(pRtnExchangeStatusData);
		}

		/**
		* �����ѯ��Ӧ
		* @param pDepthMarketData:ָ�������ѯ��Ӧ��ַ��ָ�롣
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryDepthMarketData(struct DFITCDepthMarketDataField * pDepthMarketData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryDepthMarketData(pDepthMarketData, pErrorInfo, bIsLast);
		}

		/**
		* ���ʲ�ѯ��Ӧ
		* @param pExchangeRate:ָ����ʲ�ѯ��Ӧ��ַ��ָ�롣
		* @param pErrorInfo:����ѯʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryExchangeRate(struct DFITCExchangeRateField *pExchangeRate, DFITCErrorRtnField *pRspInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryExchangeRate(pExchangeRate, pRspInfo, bIsLast);
		}

		/**
		* ���鴥����ѯ��Ӧ:���û��������鴥����ѯָ���ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pQryPricesTriggerRspData:���������ѯ��Ϣ�ṹ�ĵ�ַ��
		* @param pErrorInfo:������Ϣ�ṹ��������鴥�����������򷵻ش�����Ϣ��
		* @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
		*/
		virtual void OnRspQryPricesTrigger(struct DFITCQryPricesTriggerField  *pQryPricesTriggerRspData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryPricesTrigger(pQryPricesTriggerRspData, pErrorInfo, bIsLast);
		}

		/**
		* ������ί�б�����Ӧ:���û�¼�뱨����ǰ�÷�����Ӧʱ�÷����ᱻ���á�
		* @param pOrderRsp:�����û��µ���Ϣ�ṹ��ַ��
		* @param pErrorInfo:������ʧ�ܣ����ش�����Ϣ��ַ��
		*/
		virtual void OnRspExtInsertOrder(struct DFITCExtOrderRspDataField * pOrderRsp, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspExtInsertOrder(pOrderRsp, pErrorInfo);
		}

		/**
		* ������ί�г�����Ӧ:���û�������ǰ�÷�����Ӧ�Ǹ÷����ᱻ���á�
		* @param pOrderCancelRsp:���س�����Ӧ��Ϣ�ṹ��ַ��
		* @param pErrorInfo:������ʧ�ܣ����ش�����Ϣ��ַ��
		*/
		virtual void OnRspExtCancelOrder(struct DFITCExtOrderRspDataField * pOrderCancelRsp, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspExtCancelOrder(pOrderCancelRsp, pErrorInfo);
		}

		/**
		* ������ί�лر�:���û�¼�뱨������������÷����ᱻ���á�
		* @param pOrderRtn:�����û��µ���Ϣ�ṹ��ַ��
		*/
		virtual void OnRtnPricesTrigger(struct DFITCPricesTriggerRtnField * pOrderRtn) 
		{
			m_owner->callOnRtnPricesTrigger(pOrderRtn);
		}
	};

	public ref class CLRDFITCTraderApi
	{
	public:
		CLRDFITCTraderApi()
		{
			m_pNativeApi = DFITCXSPEEDAPI::DFITCTraderApi::CreateDFITCTraderApi();
		}
		~CLRDFITCTraderApi()
		{
			if (m_pNativeApi)
			{
				delete m_pNativeApi;
				m_pNativeApi = 0;
			}
		}
		/**
          * ɾ���ӿڶ���������ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
          */
         void Release(void);

         /**
          * �ͷ���������socket���ӣ�������һ�������̣߳� ͬʱ�÷���ע��һ���ص�������
          * @param pszFrontAddr:����ǰ�������ַ��
          *                     �����ַ�ĸ�ʽΪ:"protocol://ipaddress:port",��"tcp://172.21.200.103:10910"
          *                     ����protocol��ֵΪtcp��ʽ��
          *                     ipaddress��ʾ����ǰ�õ�IP,port��ʾ����ǰ�õĶ˿�     
          * @param^ Spi:��DFITCTraderSpi����ʵ��
          * @return 0 - ��ʼ���ɹ�; -1 - ��ʼ��ʧ�ܡ�
          */
         int Init(String^ FrontAddr, CLRDFITCTraderSpi^ Spi);

         /**
          * �ȴ��ӿ��߳̽������С�
          * @return �߳��˳����롣
          */
         int Join(void);

         /**
          * �û�������¼����
          * @param pUserLoginData:ָ���û���¼����ṹ�ĵ�ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */ 
         int ReqUserLogin(CLRDFITCUserLoginField^ UserLoginData);

         /**
          * �û������ǳ�����
          * @param pUserLogoutData:ָ���û���¼����ṹ�ĵ�ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */ 
         int ReqUserLogout(CLRDFITCUserLogoutField^ UserLogoutData);

         /**
          * �ڻ���Ȩί�б�������
          * @param pInsertOrderData:�û����󱨵���Ϣ�ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqInsertOrder(CLRDFITCInsertOrderField^ InsertOrderData);

         /**
          * �ڻ���Ȩ��������
          * @param pCancelOrderData:�û����󳷵���Ϣ�ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          * (����ṩ��̨ί�к�(��̨ί�кŴ���-1)����ֻʹ�ù�̨ί�кŴ���ֻ�е���̨ί�к�С��0ʱ����ʹ�ñ���ί�кŽ��г���)
          */
         int ReqCancelOrder(CLRDFITCCancelOrderField^ CancelOrderData);

         /**
          * �ֲֲ�ѯ����
          * @param pPositionData:�û�����ֲ���Ϣ�ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          *�����û���ṩ��Լ���룬���ѯȫ���ֲ���Ϣ����
          */
         int ReqQryPosition(CLRDFITCPositionField^ PositionData);

         /**
          * �ͻ��ʽ��ѯ����
          * @param pCapitalData:�����ʽ��ѯ�ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqQryCustomerCapital(CLRDFITCCapitalField^ CapitalData);

         /**
          * ��ѯ��������Լ�б�����������
          * @param pExchangeInstrumentData:��������Լ��ѯ�ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqQryExchangeInstrument(CLRDFITCExchangeInstrumentField^ ExchangeInstrumentData);

         /**
          * ��ѯ������������Լ�б�
          * @param pAbtriInstrumentData:������������Լ��ѯ�ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqQryArbitrageInstrument(CLRDFITCAbiInstrumentField^ AbtriInstrumentData);

         /**
          * ����ί�в�ѯ����
          * @param pOrderData:����ί�в�ѯ�ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqQryOrderInfo(CLRDFITCOrderField^ OrderData);

         /**
          * ���ճɽ���ѯ����
          * @param pMatchData:���ճɽ���ѯ�ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqQryMatchInfo(CLRDFITCMatchField^ MatchData);

         /**
          * ָ����Լ��Ϣ����Լ��֤���ʣ��������ʣ���ѯ����
          * @param pInstrument:ָ����Լ��ѯ�ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqQrySpecifyInstrument(CLRDFITCSpecificInstrumentField^ Instrument);

         /**
          * �ֲ���ϸ��ѯ����
          * @param pPositionDetailData:�ֲ���ϸ��ѯ�ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqQryPositionDetail(CLRDFITCPositionDetailField^ PositionDetailData);

         /**
          * ����IDȷ������
          * @param pConfirmProductData:����IDȷ�Ͻṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ�� -���� -����쳣��
          */
         int ReqConfirmProductInfo(CLRDFITCProductField^ ConfirmProductData);

         /**
          * �����޸�����
          * @param pResetPasswordData:�����޸Ľṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqResetPassword (CLRDFITCResetPwdField^ ResetPasswordData);

         /**
          * �˵�ȷ������
          * @param pBillConfirmData:�˵�ȷ�Ͻṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqBillConfirm(CLRDFITCBillConfirmField^ BillConfirmData);

         /**
          * ���ױ����ѯ����
          * @param pTradeCodeData:���ױ����ѯ����ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqQryTradeCode(CLRDFITCQryTradeCodeField^ TradeCodeData);

         /**
          * ��ѯ�ͻ�Ȩ����㷽ʽ����
          * @return 0 - �����ͳɹ�; -1 - ������ʧ�ܡ�
          */
         int ReqEquityComputMode();

         /**
          * �ͻ��˵������ѯ����
          * @param pQryBillData:�ͻ��˵���������ṹ��ַ�� 
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqQryBill(CLRDFITCQryBillField^ QryBillData);

         /**
          * �����ղ�ѯ����
          * @param pTradingDay:�����ղ�ѯ����ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ�� -���� -����쳣��
          */
         int ReqTradingDay(CLRDFITCTradingDayField^ TradingDay);

         /**
          * ѯ��֪ͨ��ѯ����
          * @param pQryQuoteNoticeData:��ѯѯ��֪ͨ����ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqQryQuoteNotice(CLRDFITCQryQuoteNoticeField^ QryQuoteNoticeData);

         /**
          * �����̱�������
          * @param pQuoteInsertOrderData:�����̱�������ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqQuoteInsert(CLRDFITCQuoteInsertField^ QuoteInsertOrderData) ;

         /**
          * �����̳�������
          * @param pQuoteCancelOrderData:�����̳�������ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqQuoteCancel(CLRDFITCCancelOrderField^ QuoteCancelOrderData);  

         /**
          * ��������������
          * @param pCancelAllOrderData:������������ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqCancelAllOrder(CLRDFITCCancelAllOrderField^ CancelAllOrderData);

         /**
          * ѯ������
          * @param pForQuoteData:ѯ������ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqForQuote(CLRDFITCForQuoteField^ ForQuoteData);

         /**
          * ѯ��ί�в�ѯ����
          * @param pQryForQuoteData:ѯ��ί�в�ѯ����ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqQryForQuote(CLRDFITCQryForQuoteField^ QryForQuoteData);

         /**
          * �����̱���ί�в�ѯ
          * @param pQuoteOrderData:�����̱���ί�в�ѯ�ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqQryQuoteOrderInfo(CLRDFITCQuoteOrderField^ QuoteOrderData);

         /**
          * ��ѯת������
          * @param pQryTransferBank:��ѯת����������ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqQryTransferBank(CLRDFITCQryTransferBankField^ QryTransferBank);

         /**
          * ��ѯת����ˮ
          * @param pQryTransferSerial:��ѯת����ˮ����ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqQryTransferSerial(CLRDFITCQryTransferSerialField^ QryTransferSerial);

         /**
          * �ڻ����������ʽ�ת�ڻ�
          * @param pReqTransfer:�����ʽ�ת�ڻ�����ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqFromBankToFutureByFuture(CLRDFITCReqTransferField^ ReqTransfer);

         /**
          * �ڻ������ڻ��ʽ�ת����
          * @param pReqTransfer:�ڻ��ʽ�ת��������ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqFromFutureToBankByFuture(CLRDFITCReqTransferField^ ReqTransfer);

         /**
          * ������״̬��ѯ
          * @param pQryExchangeStatusData:������״̬��ѯ����ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqQryExchangeStatus(CLRDFITCQryExchangeStatusField^ QryExchangeStatusData);

         /**
          * �����ѯ����
          * @param pQryDepthMarketData:�����ѯ����ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqQryDepthMarketData(CLRDFITCQryDepthMarketDataField^ QryDepthMarketData);

         /**
          * ���ʲ�ѯ����
          * @param pQryExchangeRate:���ʲ�ѯ����ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqQryExchangeRate(CLRDFITCQryExchangeRateField^ QryExchangeRate);

         /**
          * ���鴥������
          * @param pPricesTriggerData:���鴥������ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqPricesTrigger(CLRDFITCPricesTriggerField^ PricesTriggerData);

         /**
          * ��������ѯ����
          * @param pQryEXOrderData:��������ѯ����ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
         int ReqQryExtOrder(CLRDFITCQryExtOrderField^ QryEXOrderData);

         /**
          * ��������������
          * @param pCancelEXOrderData:��������������ṹ��ַ��
          * @return 0 - �����ͳɹ� -1 - ������ʧ��  -���� -����쳣��
          */
		 int ReqCancelExtOrder(CLRDFITCCancelExtOrderField^ CancelEXOrderData);
	public:
		DFITCXSPEEDAPI::DFITCTraderApi *m_pNativeApi;
	};

}
