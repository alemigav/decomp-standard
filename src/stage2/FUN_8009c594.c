/* FUN_8009c594
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009c594  body 0x8009c594..0x8009c65f  size 204 B
 * body sha256 ebc06e8debc2fa4fdad0f91ade9a94ffed2f4103a30652880b1046e920c41629
 * provider record sha256 56d84c45980681244171fbe281d270822c24f92c3d9034dfdcfc445e64176030
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009c594(void)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  puVar2 = DAT_80132748;
  do {
    if ((puVar2[1] & 0x10) != 0) {
      *puVar2 = 0;
    }
    uVar3 = uVar3 + 1;
    puVar2 = puVar2 + 0xc;
  } while (uVar3 < (uint)(int)DAT_80132738);
  if (((DAT_8013272c == '\x01') && (DAT_80132744 = 0, DAT_80119e70 == '\0')) &&
     ((iVar1 = FUN_8002767c(0), iVar1 != 0 || (DAT_800e9184 == 0x7fff)))) {
    DAT_80132740 = 0;
    FUN_8009e8d4(0,1);
    DAT_8013272c = '\x02';
    DAT_8013273a = 0x5a;
    DAT_8013273c = DAT_8013273e;
  }
  return;
}
