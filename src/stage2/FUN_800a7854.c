/* FUN_800a7854
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a7854  body 0x800a7854..0x800a796f  size 284 B
 * body sha256 f0dbe24bfdcc83b57c95d7954e821f02881a72b72f40b2084c55c3df044068f7
 * provider record sha256 29977224d7f9b6381a15db82910a7b9243da0675d438853ab8ebc9aa058c5e67
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800a7854(undefined4 param_1,uint param_2)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = 0xffffffff;
  uVar2 = FUN_800af0d4();
  if (uVar2 != 0xffffffff) {
    uVar6 = (param_2 & 0xffff) >> 7;
    do {
      uVar5 = uVar2 & 0xff;
      iVar3 = uVar5 * 0x1a0;
      if (*(uint *)(&DAT_801444a8 + iVar3) != uVar2) {
        return uVar4;
      }
      if ((*(uint *)(&DAT_8014446c + iVar3) & 2) == 0) {
        FUN_800ac614(0x84,uVar5,*(undefined1 *)(iVar3 + -0x7febbb6d),uVar6 & 0xff);
        uVar1 = *(undefined1 *)(iVar3 + -0x7febbb6d);
      }
      else {
        FUN_800ac614(0x84,uVar5,*(undefined1 *)(iVar3 + -0x7febbb63),uVar6 & 0xff);
        uVar1 = *(undefined1 *)(iVar3 + -0x7febbb63);
      }
      FUN_800ac614(0x85,uVar5,uVar1,param_2 & 0x7f);
      uVar2 = *(uint *)(uVar5 * 0x1a0 + -0x7febbba8);
      uVar4 = 0;
    } while (uVar2 != 0xffffffff);
  }
  return uVar4;
}
