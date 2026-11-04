/* func_80161cf0
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x8016200f  size 800 B
 * body sha256 5ea2776e119545168d4e5f8a89c5f299e4e3234fbd72e95d14ddb2df957b8a7b
 * provider record sha256 858f9a229ed6c8c7c9d7165366c45df36099b0354dd3776fcf522e86be25686c
 * callees 11 direct (10 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  uint *in_a0;
  undefined4 *puVar4;
  uint uVar5;
  
  uVar5 = in_a0[0x8d];
  if ((_DAT_800e1110 & 0x20000000) == 0) {
    *(undefined1 *)((int)in_a0 + 0x25d) = 5;
    if ((*(byte *)((int)in_a0 + 0x26f) & 0x7f) != 0) {
      *(byte *)((int)in_a0 + 0x26f) = *(byte *)((int)in_a0 + 0x26f) - 1;
    }
    (*(code *)(&PTR_FUN_801660b0)[*(byte *)(in_a0 + 1)])();
    func_0x80036c44();
    in_a0[0x94] = (uint)&DAT_800e1130;
    in_a0[0xaf] = in_a0[1];
    in_a0[0x1c] = uVar5 + 0xa80;
    uVar1 = *(undefined2 *)(in_a0 + 0x19);
    *in_a0 = *in_a0 | 0x2000000;
    uVar2 = *(undefined2 *)((int)in_a0 + 0x66);
    uVar3 = *(undefined2 *)(in_a0 + 0x1a);
    *(undefined2 *)(in_a0 + 0x19) = 0;
    *(undefined2 *)((int)in_a0 + 0x66) = 0;
    *(undefined2 *)(in_a0 + 0x1a) = 0;
    func_0x8004da40();
    *(undefined2 *)(in_a0 + 0x19) = uVar1;
    *(undefined2 *)((int)in_a0 + 0x66) = uVar2;
    *in_a0 = *in_a0 & 0xfdffffff;
    in_a0[0x1c] = 0x800e9028;
    *(undefined1 *)((int)in_a0 + 0xd) = 0xff;
    *(undefined2 *)(in_a0 + 0x1a) = uVar3;
    puVar4 = (undefined4 *)&DAT_800e13e8;
    if (_DAT_800df93c != (undefined4 *)&DAT_800e13e8) {
      do {
        if ((in_a0 != (uint *)*puVar4) && ((*(uint *)*puVar4 & 1) != 0)) {
          func_0x8004d3a0();
        }
        puVar4 = puVar4 + 1;
      } while (puVar4 != _DAT_800df93c);
    }
    FUN_80163210();
    FUN_80162e00();
    if ((in_a0[0xad] & 0x40000) != 0) {
      if ((in_a0[0x97] & 0x4000000) == 0) {
        func_0x800347b0();
      }
      else {
        func_0x80034280();
      }
    }
    *(short *)(uVar5 + 0x92c) = *(short *)(uVar5 + 0x92c) + *(short *)((int)in_a0 + 0x2c6);
    func_0x80040e58(uVar5 + 0x928,uVar5 + 0x8d8);
    *(short *)(uVar5 + 0x92c) = *(short *)(uVar5 + 0x92c) - *(short *)((int)in_a0 + 0x2c6);
    *(short *)(uVar5 + 0xaa4) = *(short *)(uVar5 + 0xaa4) + *(short *)(in_a0 + 0xb1);
    func_0x80040e58(uVar5 + 0xaa0,uVar5 + 0xa50);
    *(short *)(uVar5 + 0xaa4) = *(short *)(uVar5 + 0xaa4) - *(short *)(in_a0 + 0xb1);
    if ((in_a0[0xad] & 0x20000) == 0) {
      FUN_80163138();
    }
    if ((*(uint *)in_a0[0x85] & 0xf8000000) == 0x28000000) {
      *(undefined1 *)((int)in_a0 + 0x2c3) = 1;
    }
    FUN_80163764();
    if ((*(uint *)in_a0[0x85] & 0xf8000000) == 0x48000000) {
      *(undefined1 *)((int)in_a0 + 0x2ce) = 0x37;
    }
    func_0x80033648();
    if (*(char *)((int)in_a0 + 0x2ce) != '\0') {
      *(char *)((int)in_a0 + 0x2ce) = *(char *)((int)in_a0 + 0x2ce) + -1;
    }
    if (*(char *)(in_a0 + 0xb2) != '\0') {
      *(char *)(in_a0 + 0xb2) = *(char *)(in_a0 + 0xb2) + -1;
    }
    if ((code *)in_a0[0xb4] != (code *)0x0) {
      (*(code *)in_a0[0xb4])();
    }
    if (*(char *)((int)in_a0 + 0x2cf) != '\0') {
      *(char *)((int)in_a0 + 0x2cf) = *(char *)((int)in_a0 + 0x2cf) + -1;
    }
    if (*(char *)((int)in_a0 + 0x2ca) != '\0') {
      *(char *)((int)in_a0 + 0x2ca) = *(char *)((int)in_a0 + 0x2ca) + -1;
    }
    if (*(char *)(in_a0 + 0xb5) != '\0') {
      *(char *)(in_a0 + 0xb5) = *(char *)(in_a0 + 0xb5) + -1;
    }
    *(undefined1 *)((int)in_a0 + 0x25d) = 6;
  }
  return;
}
