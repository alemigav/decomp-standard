/* FUN_8016852c
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x8016852c  body 0x8016852c..0x801685ff  size 212 B
 * body sha256 9d9503b8ec5251f1ee7262dc0dbb3527280d15ca17d83dba4a0ab8396aac2281
 * provider record sha256 6a3f2a207a6a7218850b7e1f064c6613b2ec783e46575d69acfc281cd96faefa
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016852c(int param_1,int param_2,int param_3,uint param_4,short param_5,int param_6,
                 undefined4 param_7)

{
  int iVar1;
  short local_20;
  short local_1e;
  short local_1c;
  
  iVar1 = *(int *)(param_1 + 0x234) + param_6 * 0x178;
  func_0x8004276c(iVar1 + 0x38,param_7,&local_20);
  local_20 = local_20 + *(short *)(iVar1 + 0x4e);
  local_1e = local_1e + *(short *)(iVar1 + 0x52);
  local_1c = local_1c + *(short *)(iVar1 + 0x56);
  func_0x80037780(param_2 << 0x18 | param_3 << 0x10 | param_4,(int)param_5,&DAT_800e9028,&local_20);
  return;
}
