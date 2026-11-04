/* FUN_801658f4
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801658f4  body 0x801658f4..0x8016598b  size 152 B
 * body sha256 18d3a20c2d1dcfc3c6fa202972dc7d631ff838b67e74d19a24fa1f990eb430e5
 * provider record sha256 6422a17973785192ceeccff599c837aa63b1a13c88d45b9989bac48d2195f515
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801658f4(int param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  bVar1 = *(byte *)(param_1 + 0x2cd);
  iVar3 = *(int *)(param_1 + 0x208);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)(param_1 + 0x2cd) = 1;
    func_0x800341dc(iVar3,0xaf4faf00);
    *(undefined1 *)(param_1 + 0x207) = 0x5a;
  }
  *(short *)(iVar3 + 4) = *(short *)(iVar3 + 4) + 10;
  *(short *)(iVar3 + 6) = *(short *)(iVar3 + 6) + 0xe;
  cVar2 = *(char *)(param_1 + 0x207);
  *(char *)(param_1 + 0x207) = cVar2 + -1;
  if (cVar2 == '\x01') {
    *(undefined1 *)(param_1 + 0x2cd) = 2;
  }
  return;
}
