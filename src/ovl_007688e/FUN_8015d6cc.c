/* FUN_8015d6cc
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015d6cc  body 0x8015d6cc..0x8015d753  size 136 B
 * body sha256 a5def7bb9e923abec52107975e86c9a8c285923382b0c3f1021da8d1c441235e
 * provider record sha256 145edb2d3509d704fca89d633e7bbd4f328a10af8846a7bb05a329f00bf4fbcc
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015d6cc(void)

{
  _DAT_800e10ec = _DAT_800e10ec | 0x8000000;
  overlay_slot_reader(1,4);
  func_0x8004cd88(1);
  DAT_800e923f = 1;
  _DAT_800e10ec = _DAT_800e10ec & 0xf7ffffff;
  FUN_8015b26c();
  DAT_80160c1c = 1;
  return;
}
