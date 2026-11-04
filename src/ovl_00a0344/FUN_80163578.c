/* FUN_80163578
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80163578  body 0x80163578..0x8016370b  size 404 B
 * body sha256 9ddafaea4529bfa2d7be539c0308e3571855ba1f1bb999fe0b69a502172a0ca4
 * provider record sha256 af38f5697a35f383650e87f3495cbe574d079fe8c7c1fb44d03749f34951e842
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163578(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  undefined4 uVar5;
  
  if (*(char *)((int)param_1 + 6) == '\0') {
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined2 *)((int)param_1 + 0x212) = 0x1000;
    *param_1 = *param_1 | 0x800;
    uVar2 = func_0x80033604();
    uVar3 = func_0x80033604();
    *(undefined2 *)(param_1 + 0x7d) = 1;
    param_1[0x7a] = ((uVar2 & 1) + 5) * 0x1000000 + (uVar3 & 7) * 0x10000 + 0x700;
    *(undefined2 *)((int)param_1 + 0x66) = 0x800;
    func_0x80035b84(param_1);
    if ((_DAT_800e1128 & 0x10) == 0) {
      func_0x80077d18(8,param_1);
    }
    _DAT_800e1128 = _DAT_800e1128 | 0x10;
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  sVar1 = *(short *)(param_1 + 0x7d);
  *(short *)(param_1 + 0x7d) = sVar1 + -1;
  uVar2 = 0;
  if (sVar1 == 1) {
    *param_1 = *param_1 & 0xfffff7ff;
    do {
      uVar5 = 5;
      if (0x800 < *(short *)((int)param_1 + 0x212)) {
        uVar5 = 4;
      }
      FUN_80163bb8(param_1,uVar2 & 0xff,uVar5);
      uVar2 = uVar2 + 1;
    } while (uVar2 < 3);
    *(undefined2 *)(param_1 + 0x7d) = 0xc;
    *param_1 = *param_1 | 0x800;
  }
  FUN_80163b50(param_1);
  uVar4 = *(short *)((int)param_1 + 0x212) - 0x20;
  *(ushort *)((int)param_1 + 0x212) = uVar4;
  if ((int)((uint)uVar4 << 0x10) < 0) {
    *(undefined2 *)((int)param_1 + 0x212) = 0;
    param_1[1] = 0x7000000;
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x4000;
  }
  return;
}
