/* FUN_8007a8e8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007a8e8  body 0x8007a8e8..0x8007a903  size 28 B
 * body sha256 ec8eaf389710143c508624620938e0a7696aea6b44b7950c75c29860c7b64cd7
 * provider record sha256 b4149a8f43cd90f33a40e872b43a0b6c7f586a5e0577b678c3ee6679ccdb926d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007a8e8(int param_1)

{
  if ((*(ushort *)(param_1 + 0x1aa) & 0x100) != 0) {
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xfeff;
  }
  return;
}
