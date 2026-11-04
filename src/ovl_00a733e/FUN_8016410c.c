/* FUN_8016410c
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x8016410c  body 0x8016410c..0x801643cb  size 704 B
 * body sha256 1d2203b5fd36fde98a8d4d99a75af59eb80641409402591d06d8ffd547f32d57
 * provider record sha256 6310c2cd7a38841ba20e57add68a63ac9d16a5ed6b5f76e55c42081d9a397ec9
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016410c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (*(char *)((int)param_1 + 7) == '\0') {
    *(undefined1 *)((int)param_1 + 7) = 1;
    *param_1 = *param_1 | 2;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    _DAT_800e1354 = param_1[0x89];
    _DAT_800e1134 = 0x6000000;
    _DAT_800e1358 = param_1[0x8a];
    DAT_800e139f = DAT_800e139f | 0x80;
    _DAT_800e1380 = param_1;
    func_0x800331fc(&DAT_800e1130,param_2,param_3,0);
    _DAT_800e1196 = *(short *)((int)param_1 + 0x66) + 0x800;
    _DAT_800e1130 = _DAT_800e1130 | 0x4a;
    *(undefined1 *)(param_1 + 0xb1) = 1;
    *(undefined1 *)((int)param_1 + 0x2c5) = 1;
    *(undefined4 *)(param_1[0x8d] + 0x930) = 0xf0f3f;
    _DAT_800e10ec = _DAT_800e10ec | 0x4000100;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar1 != 0) {
    *(undefined2 *)((int)param_1 + 6) = 0x200;
  }
  func_0x80032b5c(param_1,0);
  func_0x80033648(param_1);
  uVar3 = *(uint *)param_1[0x85];
  if ((uVar3 & 0x100000) != 0) {
    uVar2 = func_0x80033604();
    if ((0x5ffa >> (uVar2 & 0xf) & 1U) != 0) {
      uVar2 = func_0x80033604();
      FUN_80167374(param_1,6,uVar2 & 1);
    }
    uVar2 = func_0x80033604();
    if ((0x17e4 >> (uVar2 & 0xf) & 1U) != 0) {
      FUN_80167374(param_1,6,9);
    }
  }
  if ((uVar3 & 0x400000) != 0) {
    uVar2 = 0xe;
    iVar1 = 0x1490;
    do {
      uVar2 = uVar2 + 1;
      *(undefined4 *)(param_1[0x8d] + iVar1 + 0x60) = 0xf0f3f;
      iVar1 = iVar1 + 0x178;
    } while (uVar2 < 0x11);
    uVar2 = 0x14;
    iVar1 = 0x1d60;
    do {
      uVar2 = uVar2 + 1;
      *(undefined4 *)(param_1[0x8d] + iVar1 + 0x60) = 0xf0f3f;
      iVar1 = iVar1 + 0x178;
    } while (uVar2 < 0x17);
  }
  if ((uVar3 & 0x200000) != 0) {
    FUN_80167374(param_1,0xf,1);
    FUN_80167374(param_1,0x15,1);
    uVar3 = func_0x80033604();
    if ((0x17e4 >> (uVar3 & 0xf) & 1U) != 0) {
      FUN_80167374(param_1,0xe,0);
      FUN_80167374(param_1,0x10,0);
      FUN_80167374(param_1,0x14,0);
      FUN_80167374(param_1,0x16,0);
    }
  }
  return;
}
