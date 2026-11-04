/* FUN_800926a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800926a0  body 0x800926a0..0x800928eb  size 588 B
 * body sha256 0371c9cc5b007bcddcc9dfe4e9b9e32f7fdf06752070c68f7ed01d61083a7e74
 * provider record sha256 7b313226ef3549825a0586c76a60ae436575870a3b0063d415fec16b7dc08a92
 * callees 15 direct (15 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800926a0(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = DAT_800c52dc + 0x3bb64U;
  if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
    uVar2 = DAT_800c52dc + 0x3c004U;
  }
  FUN_8008d2e4(uVar2 + 0xa64);
  DAT_8012bf98 = 1;
  DAT_8012bf99 = 3;
  DAT_8012bfbd = 0;
  DAT_8012bfbc = 0;
  FUN_80093be0();
  uVar2 = DAT_800c52dc + 0x3bb64U;
  if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
    uVar2 = DAT_800c52dc + 0x3c004U;
  }
  FUN_8008ca0c(7,(uint)(byte)(&DAT_800e8ef4)[(uint)DAT_8012bfbc * 4],
               uVar2 + (uint)(byte)(&DAT_800e8ef4)[(uint)DAT_8012bfbc * 4] * 0x4b0 + 0xa64);
  iVar4 = 0x19;
  DAT_8012fb70 = 1;
  DAT_8012fb72 = 0;
  iVar3 = 4;
  do {
    iVar4 = iVar4 + -3;
    uVar2 = DAT_800c52dc + 0x3bb64U;
    if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
      uVar2 = DAT_800c52dc + 0x3c004U;
    }
    FUN_8008ca0c(iVar4,(uint)(byte)(&DAT_800e8ef4)[((uint)DAT_8012bfbc + iVar3 & 0x3f) * 4],
                 uVar2 + (uint)(byte)(&DAT_800e8ef4)[((uint)DAT_8012bfbc + iVar3 & 0x3f) * 4] *
                         0x4b0 + 0xa64);
    bVar1 = iVar3 != 0;
    iVar3 = iVar3 + -1;
  } while (bVar1);
  FUN_800274f8(0x200,0xffffe800,7,1);
  do {
    FUN_8004cd88(1);
    FUN_80043620();
    FUN_80096d90();
    FUN_800978a4();
    FUN_80097c4c();
    FUN_8008c25c(0x10,0xaf,2,(&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4]);
    FUN_80093ddc();
    FUN_80095c34();
    FUN_800962fc((&DAT_800e8eca)[(uint)DAT_8012bfa4 * 4]);
    iVar3 = FUN_8002767c(0);
  } while (iVar3 == 0);
  FUN_8006c070(1);
  return;
}
