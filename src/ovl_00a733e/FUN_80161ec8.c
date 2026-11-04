/* FUN_80161ec8
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80161ec8  body 0x80161ec8..0x80162113  size 588 B
 * body sha256 d1d4fc8a2b9919127d74dec31968e46de357989f647845f1394d879944acd3f2
 * provider record sha256 d20f621a69f6b0e57416368130e02a25857e25c725bb965f8ed79be6e1960f7e
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80161ec8(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar2;
  uint *puVar1;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  param_1[1] = 0x1000000;
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  puVar1 = param_1;
  do {
    puVar1[0xad] = 0;
    uVar3 = uVar3 + 1;
    puVar1 = puVar1 + 1;
  } while (uVar3 < 0xc);
  *(undefined2 *)(param_1 + 0x78) = 0;
  *(undefined2 *)((int)param_1 + 0x1e2) = 0;
  *(undefined2 *)(param_1 + 0x79) = 0;
  uVar2 = 900;
  if ((_DAT_800e10ec & 0x20) != 0) {
    uVar2 = 0x2ee;
  }
  *(undefined2 *)((int)param_1 + 0x1f2) = uVar2;
  *(undefined2 *)((int)param_1 + 0x2c2) = 0x28;
  *param_1 = *param_1 | 0x1c000000;
  func_0x800339dc(param_1 + 0x82,0,0x6400640,0,param_1 + 10);
  uVar4 = 0;
  uVar3 = param_1[0x8d];
  param_1[0x94] = (uint)&DAT_800e1130;
  *(undefined1 *)((int)param_1 + 0x25d) = 3;
  *(undefined1 *)(param_1 + 0x97) = 0;
  *(undefined2 *)(uVar3 + 0x59c) = 0x40;
  *(undefined2 *)(uVar3 + 0x59e) = 0x10;
  *(undefined2 *)(uVar3 + 0x5a0) = 0x100;
  *(undefined2 *)(uVar3 + 0x598) = 0;
  *(undefined2 *)(uVar3 + 0x59a) = 0;
  *(undefined2 *)(uVar3 + 0x5a2) = 0x20;
  puVar1 = (uint *)param_1[0x8d];
  do {
    uVar4 = uVar4 + 1;
    *puVar1 = *puVar1 | 0x8000;
    puVar1 = puVar1 + 0x5e;
  } while (uVar4 < 0x1d);
  *(undefined2 *)(param_1 + 0x4d) = 0xf830;
  *(undefined2 *)((int)param_1 + 0x136) = 0x44c;
  *(undefined2 *)(param_1 + 0x4e) = 0x44c;
  *(undefined2 *)((int)param_1 + 0x13a) = 2000;
  *(undefined2 *)(param_1 + 0x4b) = 0x4b0;
  *(undefined2 *)((int)param_1 + 0x12e) = 0x4b0;
  *(undefined2 *)((int)param_1 + 0x28a) = 900;
  DAT_80167d60 = 0;
  DAT_80167d61 = 0;
  DAT_80167d62 = 0;
  DAT_80167d64 = 0;
  DAT_80167d66 = 0;
  DAT_80167d68 = 0;
  DAT_80167d6a = 0;
  param_1[0xa1] = 1;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  DAT_80167d6b = 0;
  param_1[0x7a] = 0;
  func_0x80089d54(param_1,param_2,param_3,0x100);
  _DAT_800df9d4 = FUN_801669f4;
  _DAT_800dfad4 = FUN_80166c5c;
  if (*(short *)((int)param_1 + 0x1aa) == 1) {
    *(undefined1 *)((int)param_1 + 5) = 1;
  }
  else if (*(short *)((int)param_1 + 0x1aa) == 0x6002) {
    param_1[1] = 0x4000000;
  }
  FUN_80167bd8(param_1,0xb,0,0);
  return;
}
