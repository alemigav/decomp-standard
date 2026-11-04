/* FUN_80164698
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80164698  body 0x80164698..0x801646e3  size 76 B
 * body sha256 bf2cb402a69dc3e42cdbd4c901046642b17f091312981bbe1f43a2fc0f7af2b3
 * provider record sha256 001fc36c44ee27927e7822853c4efa069b212ddc3d2a8820a1600c245c32dce3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164698(int param_1)

{
  (*(code *)(&PTR_FUN_801672dc)[*(byte *)(param_1 + 6)])();
  *(undefined1 *)(param_1 + 0x2d6) = 1;
  *(undefined1 *)(param_1 + 0x2d7) = 1;
  return;
}
