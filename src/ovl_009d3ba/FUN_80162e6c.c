/* FUN_80162e6c
 * image   ovl_009d3ba (ovl), base 0x80161cf0
 * address 0x80162e6c  body 0x80162e6c..0x80162fc3  size 344 B
 * body sha256 853ba0ff1e615720c4e37be9267ed24d2763020b456649b2ee283c78d5ecb2f0
 * provider record sha256 c6f3a5753a4f146f28a891d94d79416c3900aa34b105a45a67ebe52f95a819f4
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162e6c(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x250);
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0xf00;
    *(undefined1 *)(param_1 + 6) = 1;
    uVar1 = func_0x80033604();
    func_0x80077adc(((uVar1 & 1) + 1) * 0x10000 | 0x4000001,param_1 + 0x28);
    cVar2 = func_0x80033144(param_1,iVar3);
    func_0x80032dbc(param_1,*(undefined4 *)(iVar3 + 0x28),*(undefined4 *)(iVar3 + 0x30),0x800);
    if (cVar2 != '\0') {
      *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x800;
      goto switchD_80162eb4_caseD_1;
    }
    break;
  case 1:
switchD_80162eb4_caseD_1:
    break;
  case 2:
    *(undefined4 *)(param_1 + 0x1e8) = 0x1000700;
    *(undefined1 *)(param_1 + 6) = 3;
  case 3:
    cVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar2;
    return;
  case 4:
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    DAT_800e139f = DAT_800e139f & 0x7f;
  default:
    goto switchD_80162eb4_default;
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
switchD_80162eb4_default:
  return;
}
