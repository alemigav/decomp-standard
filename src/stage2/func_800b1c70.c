/* func_800b1c70
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b1c70  body 0x800b1c70..0x800b1db7  size 328 B
 * body sha256 36eb9259f26fcf66e38715ebb0c17f9256df8ba374eda1d907183bb9c02d404d
 * provider record sha256 3afb1e5af1b8fdcad257772350bf1c166c7b34222756143ce0b6e89c35de1f4e
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
undefined4 func_800b1c70(undefined4 param_1,uint param_2)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  uVar5 = 0xffffffff;
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    uVar2 = FUN_800af0d4(param_1);
    if (uVar2 != 0xffffffff) {
      uVar6 = (param_2 & 0xffff) >> 7;
      do {
        uVar4 = uVar2 & 0xff;
        iVar3 = uVar4 * 0x1a0;
        if (*(uint *)(&DAT_801444a8 + iVar3) != uVar2) break;
        if ((*(uint *)(&DAT_8014446c + iVar3) & 2) == 0) {
          FUN_800ac614(1,uVar4,*(undefined1 *)(iVar3 + -0x7febbb6d),uVar6 & 0xff);
          uVar1 = *(undefined1 *)(iVar3 + -0x7febbb6d);
        }
        else {
          FUN_800ac614(1,uVar4,*(undefined1 *)(iVar3 + -0x7febbb63),uVar6 & 0xff);
          uVar1 = *(undefined1 *)(iVar3 + -0x7febbb63);
        }
        FUN_800ac614(0x21,uVar4,uVar1,param_2 & 0x7f);
        uVar2 = *(uint *)(uVar4 * 0x1a0 + -0x7febbba8);
        uVar5 = 0;
      } while (uVar2 != 0xffffffff);
    }
    FUN_800a56c0();
  }
  return uVar5;
}
