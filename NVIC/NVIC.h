#ifndef _NVIC_INT_H_
#define _NVIC_INT_H_

#include "STD_TYPES.h"

/*RATIO */
#define			NVIC_GROUPS_16_SUBGROUPS_0    (u8)3  
#define			NVIC_GROUPS_8_SUBGROUPS_2     (u8)4  
#define			NVIC_GROUPS_4_SUBGROUPS_4     (u8)5  
#define			NVIC_GROUPS_2_SUBGROUPS_8     (u8)6  
#define			NVIC_GROUPS_0_SUBGROUPS_16    (u8)7  

/*All interrupts*/
#define 		NVIC_INT0                     (u8)0
#define 		NVIC_INT1                     (u8)1
#define 		NVIC_INT2                     (u8)2
#define 		NVIC_INT3                     (u8)3
#define 		NVIC_INT4                     (u8)4
#define 		NVIC_INT5                     (u8)5
#define 		NVIC_INT6                     (u8)6
#define 		NVIC_INT7                     (u8)7
#define 		NVIC_INT8                     (u8)8
#define 		NVIC_INT9                     (u8)9
#define 		NVIC_INT10                    (u8)10
#define 		NVIC_INT11                    (u8)11
#define 		NVIC_INT12                    (u8)12
#define 		NVIC_INT13                    (u8)13
#define 		NVIC_INT14                    (u8)14
#define 		NVIC_INT15                    (u8)15
#define 		NVIC_INT16                    (u8)16
#define 		NVIC_INT17                    (u8)17
#define 		NVIC_INT18                    (u8)18
#define 		NVIC_INT19                    (u8)19
#define 		NVIC_INT20                    (u8)20
#define 		NVIC_INT21                    (u8)21
#define 		NVIC_INT22                    (u8)22
#define 		NVIC_INT23                    (u8)23
#define 		NVIC_INT24                    (u8)24
#define 		NVIC_INT25                    (u8)25
#define 		NVIC_INT26                    (u8)26
#define 		NVIC_INT27                    (u8)27
#define 		NVIC_INT28                    (u8)28
#define 		NVIC_INT29                    (u8)29
#define 		NVIC_INT30                    (u8)30
#define 		NVIC_INT31                    (u8)31
#define 		NVIC_INT32                    (u8)32
#define 		NVIC_INT33                    (u8)33
#define 		NVIC_INT34                    (u8)34
#define 		NVIC_INT35                    (u8)35
#define 		NVIC_INT36                    (u8)36
#define 		NVIC_INT37                    (u8)37
#define 		NVIC_INT38                    (u8)38
#define 		NVIC_INT39                    (u8)39
#define 		NVIC_INT40                    (u8)40
#define 		NVIC_INT41                    (u8)41
#define 		NVIC_INT42                    (u8)42
#define 		NVIC_INT43                    (u8)43
#define 		NVIC_INT44                    (u8)44
#define 		NVIC_INT45                    (u8)45
#define 		NVIC_INT46                    (u8)46
#define 		NVIC_INT47                    (u8)47
#define 		NVIC_INT48                    (u8)48
#define 		NVIC_INT49                    (u8)49
#define 		NVIC_INT50                    (u8)50
#define 		NVIC_INT51                    (u8)51
#define 		NVIC_INT52                    (u8)52
#define 		NVIC_INT53                    (u8)53
#define 		NVIC_INT54                    (u8)54
#define 		NVIC_INT55                    (u8)55
#define 		NVIC_INT56                    (u8)56
#define 		NVIC_INT57                    (u8)57
#define 		NVIC_INT58                    (u8)58
#define 		NVIC_INT59                    (u8)59
#define 		NVIC_INT60                    (u8)60
#define 		NVIC_INT61                    (u8)61
#define 		NVIC_INT62                    (u8)62
#define 		NVIC_INT63                    (u8)63
#define 		NVIC_INT64                    (u8)64
#define 		NVIC_INT65                    (u8)65
#define 		NVIC_INT66                    (u8)66
#define 		NVIC_INT67                    (u8)67
#define 		NVIC_INT68                    (u8)68
#define 		NVIC_INT69                    (u8)69
#define 		NVIC_INT70                    (u8)70
#define 		NVIC_INT71                    (u8)71
#define 		NVIC_INT72                    (u8)72
#define 		NVIC_INT73                    (u8)73
#define 		NVIC_INT74                    (u8)74
#define 		NVIC_INT75                    (u8)75
#define 		NVIC_INT76                    (u8)76
#define 		NVIC_INT77                    (u8)77
#define 		NVIC_INT78                    (u8)78
#define 		NVIC_INT79                    (u8)79
#define 		NVIC_INT80                    (u8)80
#define 		NVIC_INT81                    (u8)81
#define 		NVIC_INT82                    (u8)82
#define 		NVIC_INT83                    (u8)83
#define 		NVIC_INT84                    (u8)84
#define 		NVIC_INT85                    (u8)85
#define 		NVIC_INT86                    (u8)86
#define 		NVIC_INT87                    (u8)87
#define 		NVIC_INT88                    (u8)88
#define 		NVIC_INT89                    (u8)89
#define 		NVIC_INT90                    (u8)90
#define 		NVIC_INT91                    (u8)91
#define 		NVIC_INT92                    (u8)92
#define 		NVIC_INT93                    (u8)93
#define 		NVIC_INT94                    (u8)94
#define 		NVIC_INT95                    (u8)95
#define 		NVIC_INT96                    (u8)96
#define 		NVIC_INT97                    (u8)97
#define 		NVIC_INT98                    (u8)98
#define 		NVIC_INT99                    (u8)99
#define 		NVIC_INT100                   (u8)100
#define 		NVIC_INT101                   (u8)101
#define 		NVIC_INT102                   (u8)102
#define 		NVIC_INT103                   (u8)103
#define 		NVIC_INT104                   (u8)104
#define 		NVIC_INT105                   (u8)105
#define 		NVIC_INT106                   (u8)106
#define 		NVIC_INT107                   (u8)107
#define 		NVIC_INT108                   (u8)108
#define 		NVIC_INT109                   (u8)109
#define 		NVIC_INT110                   (u8)110
#define 		NVIC_INT111                   (u8)111
#define 		NVIC_INT112                   (u8)112
#define 		NVIC_INT113                   (u8)113
#define 		NVIC_INT114                   (u8)114
#define 		NVIC_INT115                   (u8)115
#define 		NVIC_INT116                   (u8)116
#define 		NVIC_INT117                   (u8)117
#define 		NVIC_INT118                   (u8)118
#define 		NVIC_INT119                   (u8)119
#define 		NVIC_INT120                   (u8)120
#define 		NVIC_INT121                   (u8)121
#define 		NVIC_INT122                   (u8)122
#define 		NVIC_INT123                   (u8)123
#define 		NVIC_INT124                   (u8)124
#define 		NVIC_INT125                   (u8)125
#define 		NVIC_INT126                   (u8)126
#define 		NVIC_INT127                   (u8)127
#define 		NVIC_INT128                   (u8)128
#define 		NVIC_INT129                   (u8)129
#define 		NVIC_INT130                   (u8)130
#define 		NVIC_INT131                   (u8)131
#define 		NVIC_INT132                   (u8)132
#define 		NVIC_INT133                   (u8)133
#define 		NVIC_INT134                   (u8)134
#define 		NVIC_INT135                   (u8)135
#define 		NVIC_INT136                   (u8)136
#define 		NVIC_INT137                   (u8)137
#define 		NVIC_INT138                   (u8)138
#define 		NVIC_INT139                   (u8)139
#define 		NVIC_INT140                   (u8)140
#define 		NVIC_INT141                   (u8)141
#define 		NVIC_INT142                   (u8)142
#define 		NVIC_INT143                   (u8)143
#define 		NVIC_INT144                   (u8)144
#define 		NVIC_INT145                   (u8)145
#define 		NVIC_INT146                   (u8)146
#define 		NVIC_INT147                   (u8)147
#define 		NVIC_INT148                   (u8)148
#define 		NVIC_INT149                   (u8)149
#define 		NVIC_INT150                   (u8)150
#define 		NVIC_INT151                   (u8)151
#define 		NVIC_INT152                   (u8)152
#define 		NVIC_INT153                   (u8)153
#define 		NVIC_INT154                   (u8)154
#define 		NVIC_INT155                   (u8)155
#define 		NVIC_INT156                   (u8)156
#define 		NVIC_INT157                   (u8)157
#define 		NVIC_INT158                   (u8)158
#define 		NVIC_INT159                   (u8)159
#define 		NVIC_INT160                   (u8)160
#define 		NVIC_INT161                   (u8)161
#define 		NVIC_INT162                   (u8)162
#define 		NVIC_INT163                   (u8)163
#define 		NVIC_INT164                   (u8)164
#define 		NVIC_INT165                   (u8)165
#define 		NVIC_INT166                   (u8)166
#define 		NVIC_INT167                   (u8)167
#define 		NVIC_INT168                   (u8)168
#define 		NVIC_INT169                   (u8)169
#define 		NVIC_INT170                   (u8)170
#define 		NVIC_INT171                   (u8)171
#define 		NVIC_INT172                   (u8)172
#define 		NVIC_INT173                   (u8)173
#define 		NVIC_INT174                   (u8)174
#define 		NVIC_INT175                   (u8)175
#define 		NVIC_INT176                   (u8)176
#define 		NVIC_INT177                   (u8)177
#define 		NVIC_INT178                   (u8)178
#define 		NVIC_INT179                   (u8)179
#define 		NVIC_INT180                   (u8)180
#define 		NVIC_INT181                   (u8)181
#define 		NVIC_INT182                   (u8)182
#define 		NVIC_INT183                   (u8)183
#define 		NVIC_INT184                   (u8)184
#define 		NVIC_INT185                   (u8)185
#define 		NVIC_INT186                   (u8)186
#define 		NVIC_INT187                   (u8)187
#define 		NVIC_INT188                   (u8)188
#define 		NVIC_INT189                   (u8)189
#define 		NVIC_INT190                   (u8)190
#define 		NVIC_INT191                   (u8)191
#define 		NVIC_INT192                   (u8)192
#define 		NVIC_INT193                   (u8)193
#define 		NVIC_INT194                   (u8)194
#define 		NVIC_INT195                   (u8)195
#define 		NVIC_INT196                   (u8)196
#define 		NVIC_INT197                   (u8)197
#define 		NVIC_INT198                   (u8)198
#define 		NVIC_INT199                   (u8)199
#define 		NVIC_INT200                   (u8)200
#define 		NVIC_INT201                   (u8)201
#define 		NVIC_INT202                   (u8)202
#define 		NVIC_INT203                   (u8)203
#define 		NVIC_INT204                   (u8)204
#define 		NVIC_INT205                   (u8)205
#define 		NVIC_INT206                   (u8)206
#define 		NVIC_INT207                   (u8)207
#define 		NVIC_INT208                   (u8)208
#define 		NVIC_INT209                   (u8)209
#define 		NVIC_INT210                   (u8)210
#define 		NVIC_INT211                   (u8)211
#define 		NVIC_INT212                   (u8)212
#define 		NVIC_INT213                   (u8)213
#define 		NVIC_INT214                   (u8)214
#define 		NVIC_INT215                   (u8)215
#define 		NVIC_INT216                   (u8)216
#define 		NVIC_INT217                   (u8)217
#define 		NVIC_INT218                   (u8)218
#define 		NVIC_INT219                   (u8)219
#define 		NVIC_INT220                   (u8)220
#define 		NVIC_INT221                   (u8)221
#define 		NVIC_INT222                   (u8)222
#define 		NVIC_INT223                   (u8)223
#define 		NVIC_INT224                   (u8)224
#define 		NVIC_INT225                   (u8)225
#define 		NVIC_INT226                   (u8)226
#define 		NVIC_INT227                   (u8)227
#define 		NVIC_INT228                   (u8)228
#define 		NVIC_INT229                   (u8)229
#define 		NVIC_INT230                   (u8)230
#define 		NVIC_INT231                   (u8)231
#define 		NVIC_INT232                   (u8)232
#define 		NVIC_INT233                   (u8)233
#define 		NVIC_INT234                   (u8)234
#define 		NVIC_INT235                   (u8)235
#define 		NVIC_INT236                   (u8)236
#define 		NVIC_INT237                   (u8)237
#define 		NVIC_INT238                   (u8)238
#define 		NVIC_INT239                   (u8)239


/************************************PROTOTYPES*******************************************/

extern void NVIC_voidInitPriority(void);
extern void NVIC_voidSetPriority(u8 InterruptNo, u8 Group, u8  SubGroup);


extern void NVIC_voidEnableExternalInt(u8 InterruptNo );
extern void NVIC_voidDisableExternalInt(u8 InterruptNo );


extern void NVIC_voidSetPendingFlag(u8 InterruptNo );
extern void NVIC_voidClearPendingFlag(u8 InterruptNo );


extern u8   NVIC_u8GetActiveFlag(u8 InterruptNo );

/***********************************************************************************/

extern void NVIC_voidEnableAllExceptions(void);
extern void NVIC_voidDisableAllExceptions(void);

extern void NVIC_voidEnableAllExternalInterrupt(void);
extern void NVIC_voidDisableAllExternalInterrupt(void);


extern void NVIC_voidEnableBusFaultException(void);
extern void NVIC_voidDisableBusFaultException(void);

extern void NVIC_voidEnableUsageFaultException(void);
extern void NVIC_voidDisableUsageFaultException(void);

extern void NVIC_voidEnableMemoryFaultException(void);
extern void NVIC_voidDisableMemoryFaultException(void);


/***********************************************************************************/


#include  "NVIC_config.h"


#endif
