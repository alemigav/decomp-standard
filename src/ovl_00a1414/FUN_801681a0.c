/* FUN_801681a0
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x801681a0  body 0x801681a0..0x8016841b  size 636 B
 * body sha256 47d71e5c2e629de05461722b707d61a0bab2fd934f174eb518428c50783bad63
 * provider record sha256 52b96efa4fb8f41d0ece44157eb14e58f4be43b0b37d5d5b32b9ee3c91289c37
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801681a0(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    param_1[0x7a] = 0x7000300;
    *(undefined1 *)((int)param_1 + 6) = 1;
    _DAT_800e110c = _DAT_800e110c | 0x40;
    *(undefined1 *)(param_1 + 0x97) = 1;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    _DAT_800e1322 = 0xffff;
    func_0x80037780(0x21000,(int)*(short *)((int)param_1 + 0x66),param_1[0x8d] + 0xbf8,0);
    func_0x80077adc(0x4020001,param_1 + 10);
    func_0x80052bd0(2,0);
    func_0x80052c6c(10,0xfa,0);
    func_0x80052d10(0x1e,0xfa,0x50,10);
    func_0x80052bd0(2,0x37);
    func_0x80052bd0(3,0x3c);
    func_0x80052bd0(3,0x42);
    func_0x80052bd0(8,0x4b);
    func_0x80052c6c(0x1e,0x78,0x2d);
    func_0x80052d10(0x1e,0x78,0,0x4b);
    func_0x80052c6c(5,0xfa,0xaa);
    func_0x80052d10(0x3c,0xfa,0,0xaf);
  }
  if (*(char *)((int)param_1 + 0x1e9) == '\x17') {
    func_0x80077adc(0x4030001,param_1 + 10);
  }
  if (*(byte *)((int)param_1 + 0x1e9) < 10) {
    uVar4 = param_1[0x8d];
    uVar2 = func_0x80033604();
    func_0x80037780((uVar2 & 1) << 0x10 | 0x1000,(int)*(short *)((int)param_1 + 0x66),uVar4 + 0x38,0
                   );
    uVar4 = param_1[0x8d];
    uVar2 = func_0x80033604();
    func_0x80037780((uVar2 & 1) << 0x10 | 0x1000,(int)*(short *)((int)param_1 + 0x66),uVar4 + 0xbf8,
                    0);
  }
  if (*(char *)((int)param_1 + 0x1e9) == '\x05') {
    uVar2 = param_1[0x8d];
    *(uint *)(uVar2 + 0xbc0) = *(uint *)(uVar2 + 0xbc0) | 0x80;
    *(undefined4 *)(uVar2 + 0xcf0) = 0x40;
    *(undefined4 *)(uVar2 + 0xcf4) = 0x202030;
    puVar5 = (uint *)param_1[0x8d];
    puVar5[0x4c] = 0x80;
    puVar5[0x4d] = 0x101030;
    *puVar5 = *puVar5 | 0x80;
  }
  iVar3 = func_0x80089d54(param_1,param_2,param_3,0x400);
  if (iVar3 != 0) {
    *(undefined1 *)((int)param_1 + 6) = 2;
    *param_1 = *param_1 | 2;
  }
  return;
}
