/* FUN_80167c6c
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80167c6c  body 0x80167c6c..0x80167eaf  size 580 B
 * body sha256 a650c65ea5bcefcfbc6c02cefba860405fe7c4453ef69ece94a2105c82f3227f
 * provider record sha256 8e0a990bc311a301675044564874af894160afffe503c962e8a2356a943003cb
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80167c6c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar2;
  short sVar1;
  undefined4 uVar3;
  
  switch(*(undefined1 *)((int)param_1 + 7)) {
  case 0:
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    func_0x80077d18(7,param_1);
    FUN_80162ba4(param_1,&UNK_80168bf4 + (uint)*(byte *)((int)param_1 + 0x2cb) * 8,0);
    param_1[0x7a] = 0x19000000;
    *(undefined2 *)(param_1 + 0x79) = 0;
    *(undefined2 *)(param_1 + 0x78) = 0;
    *(undefined2 *)((int)param_1 + 0x1e2) = 0;
    *(ushort *)(param_1 + 0xb2) = *(ushort *)(param_1 + 0xb2) | 2;
    *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + '\x01';
    param_1[0xb] = param_1[0xb] + 0x546;
switchD_80167cac_caseD_1:
    func_0x8008a994(param_1,param_2,param_3,0x1000);
    *(undefined1 *)((int)param_1 + 0x1e9) = 0;
    if ((int)*(short *)(param_1 + 0xb8) <= (int)param_1[0xb]) {
      param_1[0xaf] = 0;
      FUN_801629c0(param_1);
      param_1[0x7a] = 0x19000000;
      *param_1 = *param_1 & 0xfffffff7;
      *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + '\x01';
switchD_80167cac_caseD_2:
      uVar3 = 0x400;
LAB_80167df0:
      cVar2 = func_0x8008a994(param_1,param_2,param_3,uVar3);
      *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + cVar2;
    }
switchD_80167cac_default:
    sVar1 = *(short *)((int)param_1 + 0x1e2) + 0x30;
    if ((int)(param_1[0xb] + (int)*(short *)((int)param_1 + 0x1e2) + 0x48) <
        (int)*(short *)(param_1 + 0xb8)) {
      *(short *)((int)param_1 + 0x1e2) = sVar1;
      param_1[0xb] = param_1[0xb] + (int)sVar1;
      param_1[10] = param_1[10] + (int)*(short *)(param_1 + 0x78);
      param_1[0xc] = param_1[0xc] + (int)*(short *)(param_1 + 0x79);
    }
    else {
      param_1[0xb] = (int)*(short *)(param_1 + 0xb8);
    }
    return;
  case 1:
    goto switchD_80167cac_caseD_1;
  case 2:
    goto switchD_80167cac_caseD_2;
  case 3:
    if (*(short *)((int)param_1 + 0x1f2) < 0) {
      *(undefined1 *)((int)param_1 + 0x2ce) = 3;
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
      *param_1 = *param_1 & 0xfffffff3;
      goto switchD_80167cac_default;
    }
    param_1[0x7a] = 0x16000000;
    *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + '\x01';
  case 4:
    uVar3 = 0x1000;
    goto LAB_80167df0;
  case 5:
    *(undefined1 *)((int)param_1 + 0x2ce) = 3;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
    *param_1 = *param_1 & 0xfffffff3;
    FUN_80166c7c(param_1);
  default:
    goto switchD_80167cac_default;
  }
}
