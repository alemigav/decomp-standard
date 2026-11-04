/* FUN_80089a98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80089a98  body 0x80089a98..0x80089b7b  size 228 B
 * body sha256 475935cc3d03f5e7d3c1c05f82786b4b3bdbd8e3f38dfe55682675894a62c2f5
 * provider record sha256 4bf0d2c5ffcff8727989775b153974c82fea4d7bf8502f5d2a6df7ac0b820902
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80089a98(undefined4 *param_1)

{
  short sVar1;
  undefined1 auStack_40 [32];
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  short local_18 [2];
  short local_14;
  
  if ((*(ushort *)(param_1 + 0x4e) & 0x7fff) < 0x1d) {
    *(ushort *)(param_1 + 0x4e) = *(ushort *)(param_1 + 0x4e) + 1;
  }
  else {
    *param_1 = 0;
  }
  local_1e = *(undefined2 *)(param_1 + 0x4c);
  sVar1 = *(short *)((int)param_1 + 0x132) + *(short *)((int)param_1 + 0x136);
  *(short *)((int)param_1 + 0x132) = sVar1;
  param_1[0x14] = param_1[0x14] + (int)sVar1;
  local_1c = 0;
  local_20 = 0;
  FUN_80040e58(&local_20,auStack_40);
  sVar1 = *(short *)(param_1 + 0x4d);
  *(short *)(param_1 + 0x4d) = sVar1 + *(short *)(param_1 + 0x4f);
  if ((int)((uint)(ushort)(sVar1 + *(short *)(param_1 + 0x4f)) << 0x10) < 0) {
    *(undefined2 *)(param_1 + 0x4d) = 0;
  }
  local_20 = *(undefined2 *)(param_1 + 0x4d);
  local_1e = 0;
  FUN_8004276c(auStack_40,&local_20,local_18);
  param_1[0x13] = param_1[0x13] + (int)local_18[0];
  param_1[0x15] = param_1[0x15] + (int)local_14;
  return;
}
