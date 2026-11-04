/* FUN_80171240
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x80171240  body 0x80171240..0x80171293  size 84 B
 * body sha256 efac8bd4f77a978226cfa0a1b2e7bc7a3820f18f95782954db942b4fbec74da7
 * provider record sha256 2b502d316bb508cc8413e6dd0a716a1268b52129b5148982d20f2da5afc0669b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80171240(uint param_1)

{
  int unaff_s0;
  
  func_0x80026910(*(undefined2 *)(&DAT_80171cd8 + (param_1 & 0xff) * 2));
  if (unaff_s0 == -1) {
    DAT_80171dda = DAT_80171dda | 1;
  }
  return;
}
