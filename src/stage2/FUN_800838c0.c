/* FUN_800838c0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800838c0  body 0x800838c0..0x80083a4b  size 396 B
 * body sha256 b21dc0e3c9c89d6e0bce6ed294064562096166bcd2f041d46e18865bb4159723
 * provider record sha256 bbd9438d32c5bbbb61dbbbda8b8c5658f4b7192172c35c69862945c4ffeddb9c
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800838c0(undefined4 *param_1,undefined2 *param_2,undefined2 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined2 uVar3;
  undefined4 uVar2;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_68 [20];
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 auStack_48 [32];
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_54 = *param_1;
  local_50 = param_1[1];
  local_4c = param_1[2];
  FUN_80040e58(param_4,auStack_68);
  FUN_80040cf4(auStack_68,param_3);
  FUN_80041a28(param_3,param_3);
  iVar1 = (int)(short)param_3[2];
  iVar4 = (int)(short)param_3[5];
  iVar5 = iVar1 * iVar1 + iVar4 * iVar4 + (int)(short)param_3[8] * (int)(short)param_3[8];
  if (iVar5 < 0) {
    iVar5 = iVar5 + 0xfff;
  }
  iVar5 = iVar5 >> 0xc;
  iVar6 = (iVar1 << 0xc) / iVar5;
  if (iVar5 == 0) {
    trap(0x1c00);
  }
  if ((iVar5 == -1) && (iVar1 << 0xc == -0x80000000)) {
    trap(0x1800);
  }
  uVar3 = FUN_80040a58(-iVar4);
  iVar1 = iVar6 * iVar6;
  *param_2 = uVar3;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xfff;
  }
  uVar2 = FUN_80040c04(0x1000 - (iVar1 >> 0xc));
  uVar3 = FUN_80040a58(iVar6,uVar2);
  param_2[1] = uVar3;
  param_2[2] = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  FUN_80040e58(param_2,auStack_68);
  FUN_800416bc(auStack_68,auStack_48);
  local_28 = *param_3;
  local_26 = param_3[3];
  local_24 = param_3[6];
  FUN_80042824(auStack_48,&local_28,&local_20);
  uVar3 = FUN_80040a58(local_1c,local_20);
  param_2[2] = uVar3;
  return;
}
