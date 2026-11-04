/* FUN_8009e4f0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009e4f0  body 0x8009e4f0..0x8009e533  size 68 B
 * body sha256 322dfd2e301538f6c66387192d6215ab0f6dc2b0cd3110218e2b884a9a8a1e06
 * provider record sha256 6f10b6f7702a5c6c5a715496c2e9fd49d7479a1634e2002d3730e83304b17430
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009e4f0(void)

{
  if ((DAT_800e10ec & 0x200) == 0) {
    FUN_8006c070(1);
    DAT_8013272e = 0xe;
    DAT_8013273a = 0;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
