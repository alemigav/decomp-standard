/* FUN_8004cd88
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004cd88  body 0x8004cd88..0x8004cdd3  size 76 B
 * body sha256 c82ae5e39c0b6b8ef8a0746bb9e8401f4f000440fa70b7f90eeed429efeec8ce
 * provider record sha256 65c262e908c392bbf6a5131a021a5f9a67019aa6491cef5bf6e0fabb71c93a6f
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004cd88(undefined2 param_1)

{
  DAT_8010b6b8[1] = param_1;
  *DAT_8010b6b8 = 1;
  func_0x80007450(0x80139b30,0,0);
  func_0x8000dcb0(0);
  return;
}
