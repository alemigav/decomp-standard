/* FUN_8017f870
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017f870  body 0x8017f870..0x8017f94b  size 220 B
 * body sha256 a51ce6b64e5fbafcd1e0dab447526f245b727c66e47b668885ee6e0222625a03
 * provider record sha256 01aad8a382abe3e3905be1514aa2400acc7c138f7bfcee464b6e45b5142aa394
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8017f870(void)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    iVar1 = FUN_8017bbb0(0xb);
    if (0x17 < iVar1) {
      if (iVar1 < 0x400) {
        if (iVar1 < 0x80) {
          iVar1 = iVar1 + -0x18;
          puVar2 = &DAT_80184d9c;
        }
        else {
          iVar1 = iVar1 >> 6;
          puVar2 = &UNK_80184d7c;
        }
        FUN_8017bbe8((int)(char)(puVar2 + iVar1 * 2)[1]);
        iVar3 = iVar3 + (char)puVar2[iVar1 * 2];
      }
      else {
        FUN_8017bbe8(1);
        iVar3 = iVar3 + 1;
      }
      return iVar3;
    }
    if ((iVar1 != 0xf) && (iVar3 = iVar3 + 0x21, iVar1 != 8)) break;
    FUN_8017bbe8(0xb);
  }
  DAT_80185780 = 1;
  return 1;
}
