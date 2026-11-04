/* FUN_801639d0
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801639d0  body 0x801639d0..0x80163a23  size 84 B
 * body sha256 a86e781b83fb95a5665e13ba718f0f364074bd46684f78ebfce6c2015902f7cb
 * provider record sha256 e8235c5dda128b034c98d405c43832b5a6f95cab64cfad21ba89ddac84a97fa8
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801639d0(int param_1)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = func_0x80033604();
  cVar1 = (&DAT_801672bc)[uVar2 & 7];
  *(undefined1 *)(param_1 + 5) = 1;
  *(undefined2 *)(param_1 + 6) = 0;
  *(undefined2 *)(param_1 + 0x1e4) = 0;
  *(undefined2 *)(param_1 + 0x1e0) = 0;
  *(char *)(param_1 + 0x2be) = cVar1 + '<';
  return;
}
