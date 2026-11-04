/* FUN_80054500
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80054500  body 0x80054500..0x800545f3  size 244 B
 * body sha256 da424eb24d6ca338c34580acb0bdccca5a1c10ce163843f12ea69e9cd3ccca63
 * provider record sha256 fb41b1ad00c969fdde0efd85709ae116519a4c98f91580b9c586c78a523e33a3
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80054500(void)

{
  int iVar1;
  int unaff_s2;
  uint unaff_s3;
  
  if ((DAT_8010b294 & 0x80) == 0) {
    iVar1 = FUN_8008c51c(0x35);
    if (iVar1 < 0) {
      DAT_800e8609 = 0xb;
      FUN_800539a0(0,&DAT_800b8cdc,&DAT_8010da18);
    }
    else if ((DAT_8010b294 & 1) == 0) {
      FUN_80083758(&DAT_800e8ce0,0x46);
      iVar1 = FUN_8008c51c(0x35);
      iVar1 = iVar1 * 4;
      (&DAT_800e8ec8)[iVar1] = 0;
      (&DAT_800e8ec9)[iVar1] = 0;
      (&DAT_800e8eca)[iVar1] = 0;
      FUN_8008c568();
      DAT_800e8609 = 6;
    }
    else {
      FUN_800539a0(0,&DAT_800b8cdc,&DAT_8010da18);
      FUN_80053d38();
      DAT_800e8609 = 0xb;
    }
  }
  if (*(char *)(unaff_s2 + 0x2d9) == '\x01') {
    *(undefined1 *)(unaff_s2 + 0x2d9) = 0;
    DAT_800e8609 = 0xb;
  }
  if (((DAT_8010da14 & DAT_8010da18) != 0) || (unaff_s3 != DAT_800e8609)) {
    _DAT_80139be8 = 0;
    DAT_8010da18 = 0;
    DAT_8010da14 = 0;
    _DAT_80139be4 = 0;
  }
  FUN_80053d7c(1);
  FUN_80053eb8(0x16c);
  return;
}
