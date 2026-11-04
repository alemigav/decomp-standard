/* func_80161cf0
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x80161e43  size 340 B
 * body sha256 5bfa6a39b07d762464a41cdd3bbad53b793a190dbed87a6ff683d5c53ff4edcf
 * provider record sha256 9eaf6ce305ea5831179d7e40c8c38b83f6c461b77495b7f1e4f796f6740a2b92
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool processEntry entry(void)

{
  int iVar1;
  short sVar2;
  bool bVar3;
  int in_a0;
  int local_20;
  int local_1c;
  int local_18;
  short local_10;
  short local_e;
  short local_c;
  
  func_0x8008383c((int)*(short *)(in_a0 + 0x66),*(undefined4 *)(in_a0 + 0x70));
  local_20 = *(int *)(in_a0 + 0x28) + (int)local_10;
  local_1c = *(int *)(in_a0 + 0x2c) + (int)local_e;
  local_18 = *(int *)(in_a0 + 0x30) + (int)local_c;
  iVar1 = func_0x8006a75c(*(undefined4 *)(in_a0 + 0x70));
  if (iVar1 == 0) {
    func_0x800667d4(&local_20,10,1 << (*(byte *)(in_a0 + 0x1a2) & 0x1f),0x200);
    bVar3 = _DAT_800e1068 != 0;
  }
  else {
    _DAT_800e1068 = 0;
    sVar2 = func_0x80069f1c(&local_20,0,0x600,0);
    if (_DAT_8011270c != 0) {
      sVar2 = _DAT_80112712;
    }
    bVar3 = true;
    if (sVar2 < local_1c) {
      *(short *)(in_a0 + 0x2d2) = sVar2;
    }
    else {
      if (_DAT_80112708 < _DAT_80112714) {
        _DAT_80112708 = _DAT_80112714;
      }
      bVar3 = true;
      if (local_1c < _DAT_80112708) {
        *(undefined2 *)(in_a0 + 0x2d2) = _DAT_8011270a;
      }
      else {
        bVar3 = false;
      }
    }
  }
  return bVar3;
}
