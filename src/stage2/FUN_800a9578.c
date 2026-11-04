/* FUN_800a9578
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a9578  body 0x800a9578..0x800a95fb  size 132 B
 * body sha256 d3da7d6c33dad12b09547a3f1e343bb96eff5845fd187869a4edd9f862e5fd9e
 * provider record sha256 c3cc79b31dcba32dd07dc4a3443e8908bf1eb3cc82fcea29209f1829d996fae3
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a9578(void)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = 0;
  if (DAT_80147a58 != 0) {
    pcVar1 = &DAT_801481e0;
    do {
      if (*pcVar1 == '\x01') {
        FUN_800a5c50(*(undefined4 *)(pcVar1 + 8),*(undefined4 *)(pcVar1 + 0xc));
      }
      iVar2 = iVar2 + 1;
      pcVar1 = pcVar1 + 0x18;
    } while (iVar2 < (int)(uint)DAT_80147a58);
  }
  return;
}
