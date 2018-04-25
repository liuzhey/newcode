
#ifndef REG_H_
#define REG_H_

/* bit    Description
 * 31     : mod flag
 * 30     : LRC flag
 * 29     : crmu_secdata_clr_evnet_sts
 * 28     : BBL_spl_event_sts
 * 27     : used HVD_N_TAMPER_STAT
 * 26     : BBL_Vmon_sts (coin cell low voltage detect)
 * 25..24 : BBL_Fmon_sts (25:High frequency 24: Low frequency)
 * 23..21 : BBL_Tom_sts (23: High temperature 22: Low temperatur 21: Rate of change)
 * 20     : BBL_Igrid_sts (Imesh fault tamper status)
 * 19..18 : BBL_Egrid_sts (19 : emesh Latched Open 18 : emesh Latched Fault)
 * 17..0  : BBL_Tamperpin_sts ([8:0]=Tamper_N[8:0] [17:9]=Tamper_P[8:0])
 * */

#define _BIT(__n)       (1<<(__n))
#define _MASK(__n,__s)  (((1<<(__s))-1)<<(__n))
#define _VALUE(__n,__v) ((__v)<<(__n))


#define   mod_flag2	  _MASK(0,31)
#define   mod_flag	_BIT(31)
#define   high_vol_status	_BIT(27)
#define	  low_vol_status	_BIT(26)
#define   high_fre_status	_BIT(25)
#define   low_fre_status	_BIT(24)
#define	  high_temp_status  _BIT(23)
#define   low_temp_status	_BIT(22)
#define   rate_temp_status	_BIT(21)
#define   imesh_fault_status	_BIT(20)	
#define   emesh_open_status	 _BIT(19)
#define   emesh_fault_status	_BIT(18)
#define   emesh1_status		_BIT(10)
#define   emesh2_status		_BIT(11)
#define	  emesh3_status		_BIT(12)
#define	  emesh4_status		_BIT(13)
#define   tamper_N0_status  _BIT(0)
#define	  tamper_P0_status	_BIT(9)



#endif
