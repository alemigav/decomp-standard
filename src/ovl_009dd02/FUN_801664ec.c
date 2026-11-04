/* FUN_801664ec
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801664ec  body 0x801664ec..0x80166583  size 152 B
 * body sha256 02a5201b1ebd3bef4fffd6998266f1d2438623935d4b84f859712e22039de3e2
 * provider record sha256 ff31b2206a176b59a64cc94e864cd41c172a381dfa196bd7b88a07a814e76933
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801664ec(int param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  bVar1 = *(byte *)(param_1 + 0x2cf);
  iVar3 = *(int *)(param_1 + 0x208);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)(param_1 + 0x2cf) = 1;
    func_0x800341dc(iVar3,0x6f3f3f00);
    *(undefined1 *)(param_1 + 0x207) = 0x5a;
  }
  *(short *)(iVar3 + 4) = *(short *)(iVar3 + 4) + 8;
  *(short *)(iVar3 + 6) = *(short *)(iVar3 + 6) + 8;
  cVar2 = *(char *)(param_1 + 0x207);
  *(char *)(param_1 + 0x207) = cVar2 + -1;
  if (cVar2 == '\x01') {
    *(undefined1 *)(param_1 + 0x2cf) = 2;
  }
  return;
}
