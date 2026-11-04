/* FUN_801656cc
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x801656cc  body 0x801656cc..0x8016593f  size 628 B
 * body sha256 07c9dbad67fe4de089dc69331b7b79ec01c49506dcb9c2706a5832d717375c65
 * provider record sha256 581395f8fb04702e07180027ce36e286f9757fef5e23374bc667b1ecf0f8e17e
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801656cc(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar3;
  short sVar4;
  undefined2 uVar5;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 0x2b5);
  if (bVar1 == 1) {
LAB_8016573c:
    sVar4 = *(short *)(*(int *)(param_2 + 0x120) + 0x18);
    if (sVar4 != 0) {
      *(short *)(*(int *)(param_2 + 0x120) + 0x18) = sVar4 >> 1;
    }
    *(short *)(*(int *)(param_2 + 0x120) + 0xc) =
         *(short *)(*(int *)(param_2 + 0x120) + 0xc) + *(short *)(param_1 + 0x2ba);
    if (((*(short *)(param_1 + 0x2ba) < 0xa2) &&
        (sVar4 = *(short *)(param_1 + 0x2ba) + 6, *(char *)(param_1 + 0x2b7) == '\0')) &&
       (*(short *)(param_1 + 0x2ba) = sVar4, 0xa1 < sVar4)) {
      *(undefined1 *)(param_1 + 0x2b7) = 1;
      *(undefined2 *)(param_1 + 0x2ba) = 0xa2;
    }
    if ((*(short *)(*(int *)(param_2 + 0x120) + 0xc) < 0x1f41) ||
       (uVar3 = *(short *)(param_1 + 0x2ba) - 6, *(ushort *)(param_1 + 0x2ba) = uVar3,
       -1 < (int)((uint)uVar3 << 0x10))) goto LAB_80165874;
    *(undefined1 *)(param_1 + 0x2b5) = 2;
    uVar5 = 8;
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 != 0) {
        return;
      }
      *(undefined1 *)(param_1 + 0x2b5) = 1;
      uVar3 = func_0x80033604();
      *(ushort *)(param_1 + 0x2b8) = (uVar3 & 0x1f) + 0xb4;
      *(undefined2 *)(param_1 + 0x2ba) = 6;
      *(undefined1 *)(param_1 + 0x2b7) = 0;
      goto LAB_8016573c;
    }
    if (bVar1 != 2) {
      return;
    }
    *(short *)(*(int *)(param_2 + 0x120) + 0xc) =
         *(short *)(*(int *)(param_2 + 0x120) + 0xc) - *(short *)(param_1 + 0x2ba);
    if (((*(short *)(param_1 + 0x2ba) < 0xc0) &&
        (sVar4 = *(short *)(param_1 + 0x2ba) + 8, *(char *)(param_1 + 0x2b7) == '\0')) &&
       (*(short *)(param_1 + 0x2ba) = sVar4, 0xbf < sVar4)) {
      *(undefined1 *)(param_1 + 0x2b7) = 1;
      *(undefined2 *)(param_1 + 0x2ba) = 0xc0;
    }
    if ((-0x225 < *(short *)(*(int *)(param_2 + 0x120) + 0xc)) ||
       (uVar3 = *(short *)(param_1 + 0x2ba) - 8, *(ushort *)(param_1 + 0x2ba) = uVar3,
       -1 < (int)((uint)uVar3 << 0x10))) goto LAB_80165874;
    *(undefined1 *)(param_1 + 0x2b5) = 1;
    uVar5 = 6;
  }
  *(undefined2 *)(param_1 + 0x2ba) = uVar5;
  *(undefined1 *)(param_1 + 0x2b7) = 0;
LAB_80165874:
  if ((((*(uint *)(param_1 + 0x28c) < 6000) && (*(char *)(param_1 + 0x2c5) == '\0')) &&
      (iVar2 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x80), iVar2 == 0)) &&
     ((DAT_800e139f == 0 && ((*(ushort *)(param_1 + 0x2c2) & 4) == 0)))) {
    *(undefined1 *)(param_1 + 0x2b4) = 1;
    *(undefined1 *)(param_1 + 0x2b5) = 0;
    if ((_DAT_800e1322 < 1) && (-1 < *(short *)(param_1 + 0x1f2))) {
      *(undefined4 *)(param_1 + 4) = 0x1040000;
      func_0x80059e00(500,0);
      DAT_800e139f = DAT_800e139f | 0x80;
      *(undefined1 *)(param_1 + 0x2b4) = 4;
      *(undefined1 *)(param_1 + 0x2b5) = 0;
      _DAT_800e10ec = _DAT_800e10ec | 0x100;
    }
  }
  return;
}
