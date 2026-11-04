/* func_80161cf0
 * image   ovl_0097e42 (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x80161ffb  size 780 B
 * body sha256 c32f19c52bd6f3925b9cfcd106895fbcc986d516c74d6043895918be7edb8679
 * provider record sha256 36699d4688338d4fcfd195a959f7604208df1ba61f63faf0866b94690601c8ea
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  uint uVar1;
  int iVar2;
  uint *in_a0;
  
  iVar2 = (uint)*(byte *)((int)in_a0 + 0x2c2) * 0xe;
  if ((in_a0 == _DAT_800e13f0) && (DAT_80163b04 != 0)) {
    if ((_DAT_800e1322 < 1) || ((_DAT_800e10ec & 0x4000000) != 0)) {
      func_0x80052c6c(1,DAT_801638e0,0);
      if (DAT_800dfbe8 != '\0') {
        DAT_801638e0 = DAT_801638e0 + -1;
      }
      DAT_80163b10 = DAT_80163b10 + 1;
    }
    else {
      func_0x80052c6c(1,*(undefined4 *)(&DAT_80163860 + DAT_80163b04 * 4),0);
      DAT_801638e0 = 0xbe;
    }
  }
  if ((in_a0[1] & 0xffffff00) == 0x1030100) {
    in_a0[10] = (int)*(short *)(&DAT_8016393e + iVar2);
    in_a0[0xb] = (int)*(short *)(&DAT_80163940 + iVar2);
    in_a0[0xc] = (int)*(short *)(&DAT_80163942 + iVar2);
  }
  if ((_DAT_800e1110 & 0x20000000) == 0) {
    if ((*(byte *)((int)in_a0 + 0x26f) & 0x7f) != 0) {
      *(byte *)((int)in_a0 + 0x26f) = *(byte *)((int)in_a0 + 0x26f) - 1;
    }
    (*(code *)(&PTR_FUN_801638ec)[*(byte *)(in_a0 + 1)])();
    func_0x80033648();
    if ((*(ushort *)((int)in_a0 + 0x2ba) & 8) != 0) {
      if (-0x1c84 < (int)in_a0[10]) {
        in_a0[10] = 0xffffe37c;
      }
      if ((int)in_a0[10] < -27000) {
        in_a0[10] = 0xffff9688;
      }
      if ((((in_a0[0xa3] < 0x226) && (_DAT_800e115c + -0x20 < (int)in_a0[0xb])) &&
          (*(char *)((int)in_a0 + 0x2c3) == '\0')) && (DAT_800e1135 - 1 < 4)) {
        *(undefined2 *)((int)in_a0 + 0x1f2) = 0xffff;
        *(undefined1 *)((int)in_a0 + 0x2c3) = 1;
        uVar1 = DAT_80163b10;
        *(ushort *)((int)in_a0 + 0x2ba) = *(ushort *)((int)in_a0 + 0x2ba) | 4;
        *in_a0 = *in_a0 | 10;
        if (uVar1 < 0xa0) {
          func_0x80052bd0(2,0);
        }
        in_a0[1] = 0x3000000;
      }
    }
    if (DAT_80163b04 < 3) {
      DAT_80163b0c = 0;
    }
    if ((DAT_80163b08 != 0) && ((*(ushort *)((int)in_a0 + 0x2ba) & 1) == 0)) {
      in_a0[1] = 0x1020000;
    }
    if (*(char *)(in_a0 + 0xb1) != '\0') {
      if (*(char *)(in_a0 + 0xb1) == '\x01') {
        FUN_801636e4();
      }
      *(char *)(in_a0 + 0xb1) = *(char *)(in_a0 + 0xb1) + -1;
    }
    func_0x8004da40();
  }
  return;
}
