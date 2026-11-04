/* FUN_8003ddc4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003ddc4  body 0x8003ddc4..0x8003deeb  size 296 B
 * body sha256 17d3cbbf0ead355e9dc3cd48dc80a474baf8a418ada7b9b24f362480825fc23f
 * provider record sha256 d519b9aa77ed408c9308af1a0197e2e0b78cee527fb4189f154ee8232dc078ce
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003ddc4(void)

{
  int iVar1;
  uint uVar2;
  short sVar3;
  byte bVar4;
  
  if (*(char *)(DAT_800ebb94 + 3) == '\0') {
    if (*(char *)(DAT_800ebb94 + 0x21) == *(char *)(DAT_800ebb94 + 2)) {
      *(undefined1 *)(DAT_800ebb94 + 0x21) = *(undefined1 *)(DAT_800ebb94 + 0xb);
      *(undefined1 *)(DAT_800ebb94 + 0x20) =
           *(undefined1 *)
            (*(int *)(DAT_800ebb94 + 0x70) + (uint)*(byte *)(DAT_800ebb94 + 0x21) * 8 + 2);
      *(ushort *)(DAT_800ebb94 + 0x18) = *(ushort *)(DAT_800ebb94 + 0x18) & 0xdffc;
      bVar4 = FUN_80033604();
      *(byte *)(DAT_800ebb94 + 3) = bVar4 % 0x32 + 0x32;
    }
  }
  else {
    *(char *)(DAT_800ebb94 + 3) = *(char *)(DAT_800ebb94 + 3) + -1;
    if (*(char *)(DAT_800ebb94 + 3) == '\0') {
      *(ushort *)(DAT_800ebb94 + 0x18) = *(ushort *)(DAT_800ebb94 + 0x18) | 0x2003;
      uVar2 = FUN_80033604();
      iVar1 = DAT_800ebb94;
      sVar3 = *(short *)(DAT_800ebb94 + 0x3a) + (short)((uVar2 & 0xff) % 10) * -10;
      *(short *)(DAT_800ebb94 + 6) = sVar3;
      *(short *)(iVar1 + 4) = sVar3;
    }
  }
  return;
}
