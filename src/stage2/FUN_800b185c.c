/* FUN_800b185c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b185c  body 0x800b185c..0x800b1a97  size 572 B
 * body sha256 0791eda239a8cde6dd812172722a690adc092e98aab09bffb453f2a2a9f0be02
 * provider record sha256 ac2667ea69a7ddca60ae54e15f072c701498cef6a78520c84b290a466e69b671
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
undefined4
FUN_800b185c(uint param_1,undefined2 param_2,uint param_3,undefined1 param_4,undefined1 param_5,
            undefined1 param_6,undefined1 param_7,ushort param_8,undefined1 param_9,char param_10,
            undefined1 param_11)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  char cVar6;
  ushort uVar5;
  undefined4 uVar4;
  int *piVar7;
  
  iVar1 = FUN_800ad998(param_1 >> 0x10);
  if ((iVar1 == 0) ||
     (uVar2 = FUN_800ae6b4(param_1 >> 8 & 0xff,param_1 & 0xff,param_2,(param_3 & 0xff) >> 7),
     uVar2 == 0xffffffff)) {
    uVar4 = 0xffffffff;
  }
  else {
    iVar3 = uVar2 * 0x1a0;
    piVar7 = (int *)(&DAT_80144448 + iVar3);
    FUN_800ae1a0(piVar7);
    *(uint *)(&DAT_8014446c + iVar3) = *(uint *)(&DAT_8014446c + iVar3) & 0x10 | 2;
    cVar6 = FUN_800a5890(uVar2);
    if (cVar6 != '\0') {
      *(uint *)(&DAT_8014446c + iVar3) = *(uint *)(&DAT_8014446c + iVar3) | 1;
    }
    *(undefined4 *)(iVar3 + -0x7febbb1c) = 0;
    if ((param_3 & 0x80) == 0) {
      (&DAT_80144494)[iVar3] = 0;
      *(undefined1 *)(iVar3 + -0x7febbb64) = param_6;
      *(undefined1 *)(iVar3 + -0x7febbb63) = param_7;
    }
    else {
      param_3 = param_3 & 0x7f;
      (&DAT_80144494)[iVar3] = 1;
      FUN_800abad4(uVar2 & 0xff,0xff);
      *(char *)(iVar3 + -0x7febbb64) = (char)uVar2;
      *(undefined1 *)(iVar3 + -0x7febbb63) = 0xff;
    }
    *(undefined4 *)(&DAT_80144470 + iVar3) = 0x75300000;
    *(short *)(iVar3 + -0x7febbb54) = (short)(param_1 >> 0x10);
    *(undefined2 *)(iVar3 + -0x7febbafe) = param_2;
    *(undefined2 *)(iVar3 + -0x7febbb8c) = 0x400;
    *piVar7 = iVar1;
    *(undefined1 *)(iVar3 + -0x7febbaf8) = 0;
    *(uint *)(iVar3 + -0x7febbbb4) = iVar1 + (uint)param_8 * 8;
    uVar5 = (ushort)param_3 & 0xff;
    *(ushort *)(iVar3 + -0x7febbb6a) = uVar5;
    *(ushort *)(iVar3 + -0x7febbb68) = uVar5;
    *(undefined1 *)(iVar3 + -0x7febbb66) = param_4;
    *(undefined1 *)(iVar3 + -0x7febbb65) = param_5;
    *(undefined4 *)(iVar3 + -0x7febbba8) = 0xffffffff;
    *(undefined4 *)(iVar3 + -0x7febbba4) = 0xffffffff;
    *(undefined4 *)(iVar3 + -0x7febbbb0) = 0;
    *(undefined1 *)(iVar3 + -0x7febbb62) = param_9;
    *(undefined1 *)(iVar3 + -0x7febbaf9) = param_11;
    *(uint *)(&DAT_801444a8 + iVar3) = (param_1 >> 0x10) << 0x10 | (param_3 & 0xff) << 8 | uVar2;
    FUN_800ae4d8(piVar7,param_1 >> 8 & 0xff);
    if (param_10 == '\0') {
      uVar4 = *(undefined4 *)(&DAT_801444a8 + iVar3);
    }
    else {
      uVar4 = FUN_800ae300(piVar7);
    }
  }
  return uVar4;
}
