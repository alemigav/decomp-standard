/* pi_dma_programmer
 * image   boot (boot), base 0x80000480
 * address 0x80007c20  body 0x80007c20..0x80007deb  size 460 B
 * body sha256 cb177e966e97d24bd0e402542fc01ae7ec725aa976d343fcb0ebde4687c9ebe8
 * provider record sha256 cdaad74972afdc98ba2df11209294c6eca9f2935b72d16b3a85098f2c6e81f31
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 pi_dma_programmer(int param_1,int param_2,uint param_3,undefined4 param_4,int param_5)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  
  do {
  } while ((_DAT_a4600010 & 3) != 0);
  uVar5 = (uint)*(byte *)(param_1 + 9);
  iVar2 = *(int *)(uVar5 * 4 + -0x7ffed6f0);
  if (iVar2 == param_1) goto LAB_80007d6c;
  if (uVar5 == 0) {
    if ((uint)*(byte *)(iVar2 + 5) != (uint)*(byte *)(param_1 + 5)) {
      _DAT_a4600014 = (uint)*(byte *)(param_1 + 5);
    }
    if ((uint)*(byte *)(iVar2 + 6) != (uint)*(byte *)(param_1 + 6)) {
      _DAT_a460001c = (uint)*(byte *)(param_1 + 6);
    }
    if ((uint)*(byte *)(iVar2 + 7) != (uint)*(byte *)(param_1 + 7)) {
      _DAT_a4600020 = (uint)*(byte *)(param_1 + 7);
    }
    uVar3 = (uint)*(byte *)(param_1 + 8);
    if (*(byte *)(iVar2 + 8) != uVar3) {
      puVar1 = (uint *)&DAT_a4600018;
LAB_80007d58:
      *puVar1 = uVar3;
    }
  }
  else {
    if ((uint)*(byte *)(iVar2 + 5) != (uint)*(byte *)(param_1 + 5)) {
      _DAT_a4600024 = (uint)*(byte *)(param_1 + 5);
    }
    if ((uint)*(byte *)(iVar2 + 6) != (uint)*(byte *)(param_1 + 6)) {
      _DAT_a460002c = (uint)*(byte *)(param_1 + 6);
    }
    if ((uint)*(byte *)(iVar2 + 7) != (uint)*(byte *)(param_1 + 7)) {
      _DAT_a4600030 = (uint)*(byte *)(param_1 + 7);
    }
    uVar3 = (uint)*(byte *)(param_1 + 8);
    if (*(byte *)(iVar2 + 8) != uVar3) {
      puVar1 = (uint *)&DAT_a4600028;
      goto LAB_80007d58;
    }
  }
  *(int *)(uVar5 * 4 + -0x7ffed6f0) = param_1;
LAB_80007d6c:
  _DAT_a4600000 = FUN_8000e800(param_4);
  _DAT_a4600004 = (*(uint *)(param_1 + 0xc) | param_3) & 0x1fffffff;
  if (param_2 == 0) {
    piVar4 = (int *)&DAT_a460000c;
  }
  else {
    if (param_2 != 1) {
      return 0xffffffff;
    }
    piVar4 = (int *)&DAT_a4600008;
  }
  *piVar4 = param_5 + -1;
  return 0;
}
