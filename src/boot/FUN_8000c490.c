/* FUN_8000c490
 * image   boot (boot), base 0x80000480
 * address 0x8000c490  body 0x8000c490..0x8000c61f  size 400 B
 * body sha256 148d5bb0447ed74fb1d58b4bb0447ceab533261224f1fd7b9b3e21bd4bd6c923
 * provider record sha256 94c17fd82b8a5b693292cb148546a3fda3743d60b828c7ad31ad1ec8ed17c37d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8000c490(int param_1,uint param_2,undefined4 *param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_3 == (undefined4 *)0x0) {
    FUN_8000c620(0x80011b90,0x80011b94,0x2b);
  }
  do {
  } while ((_DAT_a4600010 & 3) != 0);
  uVar4 = (uint)*(byte *)(param_1 + 9);
  iVar2 = *(int *)(uVar4 * 4 + -0x7ffed6f0);
  if (iVar2 == param_1) goto LAB_8000c5ec;
  if (uVar4 == 0) {
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
LAB_8000c5d8:
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
      goto LAB_8000c5d8;
    }
  }
  *(int *)(uVar4 * 4 + -0x7ffed6f0) = param_1;
LAB_8000c5ec:
  *param_3 = *(undefined4 *)(*(uint *)(param_1 + 0xc) | param_2 | 0xa0000000);
  return 0;
}
