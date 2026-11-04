/* FUN_800805fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800805fc  body 0x800805fc..0x800807cb  size 464 B
 * body sha256 376390711fe23854df08ce6a459eb887d8094342d987a021ddbb2c4ef081424a
 * provider record sha256 220a651951aa2970ea90ff91b521fbf8791787a92ac4b77b21547d8cfde1ec50
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_800805fc(undefined2 param_1,short param_2,short param_3,short *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 auStack_60 [32];
  undefined2 local_40;
  short local_3e;
  undefined2 local_3c;
  undefined2 local_38;
  undefined2 local_36;
  undefined2 local_34;
  ushort local_30 [2];
  ushort local_2c;
  ushort local_28 [2];
  ushort local_24;
  
  local_3c = 0;
  local_40 = 0;
  local_3e = DAT_800e1196 + param_2;
  FUN_80040e58(&local_40,auStack_60);
  local_34 = 0;
  local_36 = 0;
  local_38 = param_1;
  FUN_8004276c(auStack_60,&local_38,local_30);
  iVar1 = (int)(((uint)*(ushort *)(DAT_800df938 + 0x2a) -
                ((uint)DAT_800e1158._2_2_ + (uint)local_30[0])) * 0x10000) >> 0x10;
  iVar2 = (int)(((uint)*(ushort *)(DAT_800df938 + 0x32) -
                ((uint)DAT_800e1160._2_2_ + (uint)local_2c)) * 0x10000) >> 0x10;
  uVar3 = FUN_80040bb4(iVar1 * iVar1 + iVar2 * iVar2);
  local_3e = DAT_800e1196 + param_3;
  FUN_80040e58(&local_40,auStack_60);
  FUN_8004276c(auStack_60,&local_38,local_28);
  iVar1 = (int)(((uint)*(ushort *)(DAT_800df938 + 0x2a) -
                ((uint)DAT_800e1158._2_2_ + (uint)local_28[0])) * 0x10000) >> 0x10;
  iVar2 = (int)(((uint)*(ushort *)(DAT_800df938 + 0x32) -
                ((uint)DAT_800e1160._2_2_ + (uint)local_24)) * 0x10000) >> 0x10;
  uVar4 = FUN_80040bb4(iVar1 * iVar1 + iVar2 * iVar2);
  *param_4 = DAT_800e1158._2_2_ + local_30[0];
  param_4[2] = DAT_800e1160._2_2_ + local_2c;
  if (uVar4 < uVar3) {
    *param_4 = DAT_800e1158._2_2_ + local_28[0];
    param_4[2] = DAT_800e1160._2_2_ + local_24;
    uVar3 = uVar4;
  }
  return uVar3;
}
