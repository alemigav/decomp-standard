/* FUN_80161dc0
 * image   ovl_009d3ba (ovl), base 0x80161cf0
 * address 0x80161dc0  body 0x80161dc0..0x80162083  size 708 B
 * body sha256 5e644b7e9d449d282c2bbf0d9cc82b17b5a42bd42819cb9ed42fc0ead29a3537
 * provider record sha256 bab6f0b045a7ee563615ec9dba18abe73e5641b126bc0cca6bf80a0b84e5b4af
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80161dc0(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  uint uVar2;
  byte bVar3;
  undefined4 uVar4;
  
  param_1[1] = 0x1000000;
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  *(undefined1 *)((int)param_1 + 0x26f) = 0;
  *(undefined2 *)(param_1 + 0x78) = 0;
  *(undefined2 *)(param_1 + 0x79) = 0;
  *(undefined2 *)((int)param_1 + 0x1e2) = 0;
  _DAT_800df9bc = FUN_80162e38;
  uVar1 = func_0x80033604();
  *(ushort *)(param_1 + 0x7d) = uVar1 & 0xf;
  *(undefined2 *)((int)param_1 + 0x1f2) = 0xfa;
  *(undefined2 *)(param_1 + 0xb0) = 0;
  *(undefined1 *)((int)param_1 + 0x1ed) = 0x82;
  *(undefined1 *)((int)param_1 + 0x1ee) = 0x82;
  *(undefined1 *)((int)param_1 + 0x1ef) = 0x82;
  *(undefined2 *)(param_1 + 0xad) = *(undefined2 *)((int)param_1 + 0x66);
  param_1[0xae] = param_1[10];
  param_1[0xaf] = param_1[0xc];
  if ((*(ushort *)((int)param_1 + 0x1aa) & 1) == 0) {
    bVar3 = 7;
    *(undefined1 *)(param_1 + 0x97) = 0;
    uVar2 = param_1[0x8d];
    *(undefined1 *)((int)param_1 + 0x25d) = 1;
    *(undefined2 *)(uVar2 + 0x2ac) = 0x60;
    *(undefined2 *)(uVar2 + 0x2ae) = 0x60;
    *(undefined2 *)(uVar2 + 0x2b0) = 0x200;
    *(undefined2 *)(uVar2 + 0x2a8) = 0;
    *(undefined2 *)(uVar2 + 0x2aa) = 0;
    *(undefined2 *)(uVar2 + 0x2b2) = 0x138;
    do {
      uVar2 = (uint)bVar3;
      bVar3 = bVar3 - 1;
      *(undefined4 *)(param_1[0x8d] + (uint)(byte)(&DAT_80163026)[uVar2] * 0x178) = 0;
    } while (bVar3 != 0);
    uVar4 = 0;
  }
  else {
    bVar3 = 7;
    *(undefined1 *)(param_1 + 0x97) = 0;
    uVar2 = param_1[0x8d];
    *(undefined1 *)((int)param_1 + 0x25d) = 8;
    *(undefined2 *)(uVar2 + 0xcf4) = 0x60;
    *(undefined2 *)(uVar2 + 0xcf6) = 0x60;
    *(undefined2 *)(uVar2 + 0xcf8) = 0x200;
    *(undefined2 *)(uVar2 + 0xcf0) = 0;
    *(undefined2 *)(uVar2 + 0xcf2) = 0;
    *(undefined2 *)(uVar2 + 0xcfa) = 0x138;
    do {
      uVar2 = (uint)bVar3;
      bVar3 = bVar3 - 1;
      *(undefined4 *)(param_1[0x8d] + (uint)(byte)(&UNK_8016301f)[uVar2] * 0x178) = 0;
    } while (bVar3 != 0);
    uVar4 = 1;
  }
  FUN_80162d8c(param_1,uVar4,0);
  _DAT_800e1128 = 0;
  DAT_80163130 = 0;
  param_1[0xa1] = 1;
  *(undefined2 *)((int)param_1 + 0x13a) = 500;
  *(undefined2 *)((int)param_1 + 0x136) = 800;
  *(undefined2 *)(param_1 + 0x4e) = 800;
  *(undefined2 *)(param_1 + 0x4b) = 800;
  *(undefined2 *)((int)param_1 + 0x12e) = 800;
  *(undefined2 *)((int)param_1 + 0x28a) = 800;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  *(undefined2 *)(param_1 + 0x4d) = 0;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  param_1[0x7a] = 0;
  *param_1 = *param_1 | 0xc000000;
  func_0x80089d54(param_1,param_2,param_3,0x100);
  *param_1 = *param_1 | 0x1404;
  func_0x800339dc(param_1 + 0x82,0,0x2bc0258,0,param_1[0x8d] + 0x4c);
  return;
}
