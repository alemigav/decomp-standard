/* FUN_80165ea0
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80165ea0  body 0x80165ea0..0x80165f43  size 164 B
 * body sha256 0ef8c0656d3888ab0afee12430536eb63513b59b9c110c32699604270cae52f5
 * provider record sha256 8f8c161273e4c21cef51807625a292d63dc4e9f1116fadff9a538a94ba4ea7d3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165ea0(undefined4 param_1,int param_2)

{
  byte bVar1;
  short sVar2;
  undefined2 uVar3;
  
  bVar1 = *(byte *)(param_2 + 7);
  if (bVar1 == 1) {
LAB_80165ee4:
    sVar2 = *(short *)(param_2 + 2) + 0x200;
    *(short *)(param_2 + 2) = sVar2;
    if (sVar2 < 0x300) goto LAB_80165f38;
    *(undefined1 *)(param_2 + 7) = 2;
    uVar3 = 0x300;
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 != 0) goto LAB_80165f38;
      *(undefined1 *)(param_2 + 7) = 1;
      *(undefined2 *)(param_2 + 2) = 0xff00;
      *(undefined2 *)(param_2 + 4) = 0xff00;
      goto LAB_80165ee4;
    }
    if (bVar1 != 2) goto LAB_80165f38;
    sVar2 = *(short *)(param_2 + 2) + -0x200;
    *(short *)(param_2 + 2) = sVar2;
    uVar3 = 0xff00;
    if (-0x100 < sVar2) goto LAB_80165f38;
    *(undefined1 *)(param_2 + 7) = 1;
  }
  *(undefined2 *)(param_2 + 2) = uVar3;
LAB_80165f38:
  *(undefined2 *)(param_2 + 4) = *(undefined2 *)(param_2 + 2);
  return;
}
