/* FUN_80164ec0
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80164ec0  body 0x80164ec0..0x8016516f  size 688 B
 * body sha256 975b67b1eb97ca5c67c4f763b205c94d2c9e95d36afd45b213edc824621d5587
 * provider record sha256 9a869f0019a325ad6e59f8c20b4fc6cec3ecf03afe4fedfd419d283e8fd274d2
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164ec0(uint *param_1)

{
  int iVar1;
  char cVar2;
  
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    *(undefined2 *)(param_1 + 0x9c) = 0;
    *param_1 = *param_1 | 10;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  case 1:
    if (*(short *)(param_1 + 0x9c) == 1) {
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
switchD_80164ef0_caseD_2:
      func_0x80036c68(param_1,1,0xf,0);
      if (*(short *)(param_1 + 0x9c) == 2) {
        *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
switchD_80164ef0_caseD_3:
        cVar2 = func_0x80036c68(param_1,2,0xf,0);
        *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
      }
    }
    break;
  case 2:
    goto switchD_80164ef0_caseD_2;
  case 3:
    goto switchD_80164ef0_caseD_3;
  case 4:
    if (*(short *)(param_1 + 0x9c) != 6) {
      return;
    }
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  case 5:
    func_0x80036c68(param_1,1,0xf,0);
    if (*(short *)(param_1 + 0x9c) == 3) {
      cVar2 = *(char *)((int)param_1 + 6);
      param_1[0x7a] = 0x1000700;
LAB_801650ec:
      *(char *)((int)param_1 + 6) = cVar2 + '\x01';
    }
    break;
  case 6:
    *(undefined1 *)(param_1 + 0x7a) = 1;
    func_0x800334c8(param_1,param_1[0x8b],param_1[0x8c],0);
    cVar2 = func_0x80089d54(param_1,param_1[0x8b],param_1[0x8c],0x200);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
    func_0x80032b5c(param_1,0);
  case 7:
    if (*(short *)(param_1 + 0x9c) == 4) {
      param_1[0x7a] = 0x1000000;
      *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + 0x800;
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
      func_0x80089d54(param_1,param_1[0x8b],param_1[0x8c],0x1000);
    }
    break;
  case 8:
    func_0x80036c68(param_1,1,0xf,0);
    if (*(short *)(param_1 + 0x9c) != 5) {
      return;
    }
    param_1[0x7a] = 0x4000000;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  case 9:
    *(undefined1 *)(param_1 + 0x7a) = 4;
    func_0x800334c8(param_1,param_1[0x8b],param_1[0x8c],0);
    iVar1 = func_0x80089d54(param_1,param_1[0x8b],param_1[0x8c],0x1000);
    if (iVar1 == 0) {
LAB_80165158:
      func_0x80032b5c(param_1,0);
      return;
    }
    param_1[0x7a] = 0xa0000;
    func_0x800334c8(param_1,param_1[0x8b],param_1[0x8c],0);
    cVar2 = *(char *)((int)param_1 + 6);
    goto LAB_801650ec;
  case 10:
    *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + 0x400;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  case 0xb:
    *(undefined1 *)(param_1 + 0x7a) = 0;
    func_0x800334c8(param_1,param_1[0x8b],param_1[0x8c],0);
    cVar2 = func_0x80089d54(param_1,param_1[0x8b],param_1[0x8c],0x1000);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
    goto LAB_80165158;
  default:
    break;
  }
  return;
}
