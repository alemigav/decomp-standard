/* FUN_80165670
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x80165670  body 0x80165670..0x801656cb  size 92 B
 * body sha256 1d69739b164abd5ecd26225437af49f586c0f23ab046af5e4dc87570e6be9ec6
 * provider record sha256 dcab83e61cd9167077d75afcca4ea22d9747a64f66d5d29fce07d070dd3d1deb
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165670(int param_1,int param_2)

{
  (*(code *)(&PTR_FUN_80167400)[*(byte *)(param_1 + 0x2b4)])();
  func_0x800666ec(param_1,param_2,*(undefined4 *)(param_2 + 0xb4),*(undefined4 *)(param_2 + 0x120));
  return;
}
