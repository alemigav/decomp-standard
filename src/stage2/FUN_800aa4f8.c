/* FUN_800aa4f8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aa4f8  body 0x800aa4f8..0x800aa6b7  size 448 B
 * body sha256 67e339af49929f26a94b482b62053b6e4c8d1ba8a6bd1809bbdc59d10acc53e7
 * provider record sha256 78cc676bb36a714d0963cb51e97b5e018bd44a875ca446406464c96b6fe43454
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_800aa4f8(int *param_1,int *param_2,int *param_3,int *param_4,float *param_5,int param_6,
            int param_7,int param_8,int param_9,byte param_10)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  if (DAT_80136310 == '\0') {
    uVar1 = 0;
  }
  else {
    FUN_800a5678();
    *param_1 = (int)_DAT_80148bd8;
    if (_DAT_80148bd8 != (int *)0x0) {
      _DAT_80148bd8[1] = (int)param_1;
    }
    param_1[1] = 0;
    iVar2 = param_2[1];
    iVar3 = param_2[2];
    param_1[3] = *param_2;
    param_1[4] = iVar2;
    param_1[5] = iVar3;
    iVar2 = param_3[1];
    iVar3 = param_3[2];
    param_1[6] = *param_3;
    param_1[7] = iVar2;
    param_1[8] = iVar3;
    iVar2 = param_4[1];
    iVar3 = param_4[2];
    param_1[9] = *param_4;
    param_1[10] = iVar2;
    param_1[0xb] = iVar3;
    param_1[0xf] = (int)-*param_5;
    param_1[0x10] = (int)-param_5[1];
    fVar4 = param_5[2];
    param_1[0x1e] = param_6;
    _DAT_80148bd8 = param_1;
    param_1[0x1f] = param_7;
    param_1[0x11] = (int)-fVar4;
    param_1[0x20] = param_8;
    FUN_800ab2cc(param_1 + 0xc,param_1 + 0xf,param_1 + 9);
    local_50 = param_1[0xc];
    local_44 = param_1[0xd];
    local_38 = param_1[0xe];
    local_4c = param_1[0xf];
    local_40 = param_1[0x10];
    local_34 = param_1[0x11];
    local_48 = param_1[9];
    local_3c = param_1[10];
    local_30 = param_1[0xb];
    local_2c = param_1[3];
    local_28 = param_1[4];
    local_24 = param_1[5];
    FUN_800aaf90(param_1 + 0x12,&local_50);
    param_1[2] = param_9;
    param_1[0x21] = (int)((float)param_10 / 127.0);
    FUN_800a56c0();
    uVar1 = 1;
  }
  return uVar1;
}
