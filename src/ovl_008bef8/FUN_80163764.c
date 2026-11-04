/* FUN_80163764
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80163764  body 0x80163764..0x801638cb  size 360 B
 * body sha256 a7c83c9cdb13e6559ac1782ea0ef171c36bd6c2ff17d3e4f42858f7df9914dd3
 * provider record sha256 c0d9baba5327d5e9bffe39cad447bcbecb99782b5dff0389e7be4a66432a8865
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163764(int param_1)

{
  char cVar1;
  
  switch(*(undefined1 *)(param_1 + 0x2c3)) {
  default:
    goto switchD_80163794_caseD_0;
  case 1:
    func_0x80052d10(10,0x78,0x32,0);
    *(undefined1 *)(param_1 + 0x206) = 2;
    *(char *)(param_1 + 0x2c3) = *(char *)(param_1 + 0x2c3) + '\x01';
switchD_80163794_caseD_2:
    cVar1 = *(char *)(param_1 + 0x206);
    *(char *)(param_1 + 0x206) = cVar1 + -1;
    if (cVar1 == '\x01') {
LAB_80163870:
      *(char *)(param_1 + 0x2c3) = *(char *)(param_1 + 0x2c3) + '\x01';
    }
switchD_80163794_caseD_0:
    return;
  case 2:
    goto switchD_80163794_caseD_2;
  case 3:
    *(undefined1 *)(param_1 + 0x206) = 5;
    _DAT_800e110c = _DAT_800e110c | 4;
    *(char *)(param_1 + 0x2c3) = *(char *)(param_1 + 0x2c3) + '\x01';
  case 4:
    cVar1 = *(char *)(param_1 + 0x206);
    *(char *)(param_1 + 0x206) = cVar1 + -1;
    if (cVar1 != '\x01') {
      return;
    }
    *(undefined1 *)(param_1 + 0x206) = 10;
    func_0x80052d10(8,0x55,0x28,0);
    _DAT_800e110c = _DAT_800e110c & 0xfffffffb | 8;
    goto LAB_80163870;
  case 5:
    cVar1 = *(char *)(param_1 + 0x206);
    *(char *)(param_1 + 0x206) = cVar1 + -1;
    if (cVar1 == '\x01') {
      _DAT_800e110c = _DAT_800e110c & 0xfffffff7;
      *(undefined1 *)(param_1 + 0x2c3) = 0;
    }
    goto switchD_80163794_caseD_0;
  }
}
