/* FUN_80163724
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80163724  body 0x80163724..0x8016375b  size 56 B
 * body sha256 e568184da9b73420746c1ffe653d2c708467df3e2e4edc7f613e052935eed1a5
 * provider record sha256 fa5bf5713839455d15619ceaa34f39287b5830df64b39254ff36adfe96dabe53
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163724(int param_1,undefined2 *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x234) + param_3 * 0x178;
  *param_2 = *(undefined2 *)(iVar1 + 0x4e);
  param_2[1] = *(undefined2 *)(iVar1 + 0x52);
  param_2[2] = *(undefined2 *)(iVar1 + 0x56);
  return;
}
