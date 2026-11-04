/* FUN_8008c568
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008c568  body 0x8008c568..0x8008c6c7  size 352 B
 * body sha256 634a62840d32c33ea47811df5715ae0eaac4272c4828405cf2460f84ec6d155f
 * provider record sha256 e389ad6a6ee05044dda6613dd11bba1fefaf8ad999ba792b3bc9aea43c607732
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008c568(void)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  iVar1 = FUN_8008c4b8(0);
  uVar3 = iVar1 + 1;
  if (iVar1 == 9) {
    FUN_8008cc1c(0xd);
    DAT_800e8eec = 0;
    DAT_800e8eed = 0;
    DAT_800e8eee = 0;
  }
  else if ((-1 < iVar1) && (uVar3 < 10)) {
    puVar5 = &DAT_800c76b0 + uVar3;
    iVar1 = uVar3 * 4 + -4;
    do {
      uVar4 = uVar3;
      FUN_8008cb48((uVar4 >> 1) + uVar4,((uVar4 - 1 >> 1) - 1) + uVar4);
      (&DAT_800e8ec8)[iVar1] = *(undefined1 *)(puVar5 + 0x8606);
      (&DAT_800e8ec9)[iVar1] = *(undefined1 *)((int)puVar5 + 0x21819);
      (&DAT_800e8eca)[iVar1] = *(undefined1 *)((int)puVar5 + 0x2181a);
      bVar2 = (byte)(uVar4 - 1);
      if (DAT_8012bfa0 == uVar4) {
        DAT_8012bfa0 = bVar2;
      }
      if (DAT_8012f524 == uVar4) {
        DAT_8012f524 = bVar2;
      }
      puVar5 = puVar5 + 1;
      uVar3 = uVar4 + 1;
      iVar1 = iVar1 + 4;
    } while (uVar3 < DAT_800e8b38);
    FUN_8008cc1c(((uVar4 >> 1) - 1) + uVar3);
    iVar1 = uVar4 * 4;
    (&DAT_800e8ec8)[iVar1] = 0;
    (&DAT_800e8ec9)[iVar1] = 0;
    (&DAT_800e8eca)[iVar1] = 0;
  }
  return;
}
