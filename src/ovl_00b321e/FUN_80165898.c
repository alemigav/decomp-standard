/* FUN_80165898
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80165898  body 0x80165898..0x801658f3  size 92 B
 * body sha256 e3c9b7d5966158f40e029dc85d3f24d73e5c0fd68bd00bb3794b7fabb181a918
 * provider record sha256 92c6d3181061529c9dc0c32d99241afaac99144008a4822354a771e4ebb9563f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80165898(uint *param_1)

{
  if (*(char *)((int)param_1 + 5) == '\0') {
    *(undefined1 *)((int)param_1 + 5) = 1;
    *param_1 = *param_1 | 0x42;
    _DAT_800e1128 = _DAT_800e1128 & 0xffdf;
  }
  FUN_801658f4(param_1);
  return;
}
