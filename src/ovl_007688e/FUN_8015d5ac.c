/* FUN_8015d5ac
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015d5ac  body 0x8015d5ac..0x8015d6cb  size 288 B
 * body sha256 16031be84a8f6a84726c49edbf3191e6608a89a092a015bac7875adce91d6397
 * provider record sha256 ea7586bea5f426eef111137e7d38ad1997122d57eca8e5c8656293d41607febd
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015d5ac(void)

{
  int iVar1;
  
  DAT_800e923f = 0;
  _DAT_800e10ec = _DAT_800e10ec | 0x400;
  overlay_slot_reader(1,2);
  func_0x8004cd88(1);
  DAT_800e923f = 1;
  iVar1 = (DAT_800e9012 & 3) * 4;
  _DAT_800c76b0 = *(undefined4 *)(&DAT_80160870 + iVar1);
  _DAT_800c76b4 = *(undefined4 *)(&DAT_8016087c + iVar1);
  if ((_DAT_800e10ec & 0x400) == 0) {
    _DAT_800e10ec = _DAT_800e10ec & 0xfffdffff;
    DAT_80160c1d = 3;
  }
  else if ((_DAT_800e10ec & 8) == 0) {
    _DAT_800e10ec = _DAT_800e10ec & 0xfffffbff;
    FUN_8015b26c();
    DAT_80160c1c = 1;
  }
  else {
    DAT_80160c1c = 3;
    _DAT_800e10ec = _DAT_800e10ec & 0xfffffbff;
  }
  return;
}
