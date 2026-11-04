/* FUN_80075878
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80075878  body 0x80075878..0x800759d7  size 352 B
 * body sha256 16266b017a168d1cd4fc6d59515c14354e49f1a9085749593ee8e60c1386b114
 * provider record sha256 97e81b080c5be4057dfc5d26168d40a6a765388f2480aed7ad75f00f70e0807b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80075878(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  DAT_80119d88 = (float)*param_1;
  DAT_80119d8c = (float)param_1[1];
  DAT_80119d90 = (float)param_1[2];
  DAT_80119d94 = (float)*param_2;
  DAT_80119d98 = (float)param_2[1];
  DAT_80119d9c = (float)param_2[2];
  iVar3 = *param_2 - *param_1;
  iVar4 = param_2[1] - param_1[1];
  iVar5 = param_2[2] - param_1[2];
  iVar2 = FUN_80040bb4(iVar3 * iVar3 + iVar4 * iVar4 + iVar5 * iVar5);
  fVar1 = 1.0 / (float)iVar2;
  DAT_80119da0 = fVar1 * (float)iVar3;
  DAT_80119da4 = fVar1 * (float)iVar4;
  DAT_80119da8 = fVar1 * (float)iVar5;
  FUN_800aa6b8(0x8013a170,&DAT_80119d88,&DAT_80119d94,&DAT_80119da0,&DAT_80119dac,0x7f);
  return;
}
