/* FUN_80165d8c
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80165d8c  body 0x80165d8c..0x80165fe7  size 604 B
 * body sha256 a28f156c860d61ae2a708b6ccdf95b0b4ee559a235899dc466663a65a1bfd698
 * provider record sha256 10ac5e531089c8497249e9c1397cad6d85587b1c994abd8c8a5f076f655988e8
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80165d8c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar2;
  int iVar1;
  
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    param_1[0x7a] = 0x2060300;
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x78) = 800;
    *(undefined2 *)(param_1 + 0x79) = 0;
    _DAT_800e110c = _DAT_800e110c | 0x40;
    *(undefined1 *)(param_1 + 0x97) = 1;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    *param_1 = *param_1 | 2;
    func_0x80077adc(0x4010001,param_1 + 10);
    *(undefined1 *)((int)param_1 + 0x206) = 5;
  case 1:
    cVar2 = func_0x80089d54(param_1,param_2,param_3,0x400);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
  case 2:
    param_1[10] = param_1[10] - 100;
    if (*(char *)((int)param_1 + 0x206) != '\0') {
      *(char *)((int)param_1 + 0x206) = *(char *)((int)param_1 + 0x206) + -1;
    }
    if (((param_1[0x6b] & 1) != 0) && (*(char *)((int)param_1 + 0x206) == '\0')) {
      *(undefined1 *)((int)param_1 + 6) = 3;
      param_1[0x7a] = 0x300;
      *(undefined2 *)(param_1 + 0x78) = 0;
      func_0x80077adc(0x4020001,param_1 + 10);
      func_0x80077adc(0x2290001,param_1 + 10);
      func_0x80052bd0(3,0);
      func_0x80052c6c(6,0xfa,0);
    }
    break;
  case 3:
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x400);
    if (iVar1 != 0) {
      param_1[0x7a] = 0x1000300;
      *(undefined1 *)((int)param_1 + 6) = 4;
    }
    break;
  case 4:
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x400);
    if (iVar1 != 0) {
      param_1[0x7a] = 0x6000700;
      *(undefined1 *)((int)param_1 + 6) = 5;
      *(undefined1 *)(param_1 + 0x97) = 0;
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
      *param_1 = *param_1 & 0xfffffffd;
      _DAT_800e110c = _DAT_800e110c & 0xffffffbf;
    }
    break;
  case 5:
    iVar1 = func_0x80089d54(param_1,param_1[0x69],param_1[0x86],0x10200);
    if (iVar1 != 0) {
      param_1[1] = 0x1000000;
    }
  }
  func_0x80032b5c(param_1,0x800);
  return;
}
