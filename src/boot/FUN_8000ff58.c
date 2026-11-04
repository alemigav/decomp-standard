/* FUN_8000ff58
 * image   boot (boot), base 0x80000480
 * address 0x8000ff58  body 0x8000ff58..0x800104f7  size 1440 B
 * body sha256 cd79d18cdbd3dc4251e7fb0948eb0b323d93ca45c01f13173bcc34bc5e2b65ca
 * provider record sha256 c2e144a72a57ed36bc608f228241dae3fa8ee1e2454d2e18aa9e32fbfdb1d79d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8000ff58(int param_1,byte param_2,undefined1 *param_3,int param_4,int param_5)

{
  char cVar1;
  short sVar3;
  int iVar2;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  short sVar7;
  
  if (param_4 << 0x10 < 1) {
    param_4 = 1;
    param_3 = &DAT_80011ef0;
  }
  sVar3 = (short)param_4;
  if (param_2 == 0x66) {
LAB_8000ffec:
    param_5 = param_5 + 1;
    sVar7 = (short)param_5;
    if (param_2 != 0x66) {
      if (((*(uint *)(param_1 + 0x30) & 8) == 0) && ((int)sVar3 < *(int *)(param_1 + 0x24))) {
        *(int *)(param_1 + 0x24) = (int)sVar3;
      }
      iVar2 = *(int *)(param_1 + 0x24) - (param_5 * 0x10000 >> 0x10);
      *(int *)(param_1 + 0x24) = iVar2;
      if (iVar2 < 0) {
        *(undefined4 *)(param_1 + 0x24) = 0;
      }
    }
    iVar2 = param_5 * 0x10000 >> 0x10;
    if (iVar2 < 1) {
      iVar2 = *(int *)(param_1 + 0x14);
      *(int *)(param_1 + 0x14) = iVar2 + 1;
      *(undefined1 *)(*(int *)(param_1 + 8) + iVar2) = 0x30;
      if ((0 < *(int *)(param_1 + 0x24)) || ((*(uint *)(param_1 + 0x30) & 8) != 0)) {
        iVar2 = *(int *)(param_1 + 0x14);
        *(int *)(param_1 + 0x14) = iVar2 + 1;
        *(undefined1 *)(*(int *)(param_1 + 8) + iVar2) = 0x2e;
      }
      if (*(int *)(param_1 + 0x24) < -(param_5 * 0x10000 >> 0x10)) {
        sVar7 = -(short)*(int *)(param_1 + 0x24);
      }
      *(int *)(param_1 + 0x18) = -(int)sVar7;
      iVar2 = *(int *)(param_1 + 0x24) + (int)sVar7;
      *(int *)(param_1 + 0x24) = iVar2;
      if (iVar2 < sVar3) {
        param_4 = iVar2;
      }
      iVar2 = (int)(short)param_4;
      *(int *)(param_1 + 0x1c) = iVar2;
      FUN_8000de9c(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14),param_3,iVar2);
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x24) - iVar2;
    }
    else {
      iVar4 = (int)sVar3;
      if (iVar4 < iVar2) {
        FUN_8000de9c(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14),param_3,iVar4);
        *(int *)(param_1 + 0x18) = iVar2 - iVar4;
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + iVar4;
        if ((0 < *(int *)(param_1 + 0x24)) || ((*(uint *)(param_1 + 0x30) & 8) != 0)) {
          *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = 0x2e;
          *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
        }
        *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x24);
      }
      else {
        FUN_8000de9c(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14),param_3,iVar2);
        iVar2 = *(int *)(param_1 + 0x14) + iVar2;
        *(int *)(param_1 + 0x14) = iVar2;
        if ((0 < *(int *)(param_1 + 0x24)) || ((*(uint *)(param_1 + 0x30) & 8) != 0)) {
          *(int *)(param_1 + 0x14) = iVar2 + 1;
          *(undefined1 *)(*(int *)(param_1 + 8) + iVar2) = 0x2e;
        }
        iVar2 = param_4 - param_5;
        if (*(int *)(param_1 + 0x24) < (param_4 - param_5) * 0x10000 >> 0x10) {
          iVar2 = *(int *)(param_1 + 0x24);
        }
        iVar2 = (int)(short)iVar2;
        FUN_8000de9c(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14),
                     param_3 + (param_5 * 0x10000 >> 0x10),iVar2);
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + iVar2;
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x24) - iVar2;
      }
    }
  }
  else {
    if (param_2 == 0x67 || param_2 == 0x47) {
      if ((-5 < param_5._2_2_) && ((int)param_5._2_2_ < *(int *)(param_1 + 0x24)))
      goto LAB_8000ffec;
      if (param_2 == 0x67 || param_2 == 0x47) {
        if ((int)sVar3 < *(int *)(param_1 + 0x24)) {
          *(int *)(param_1 + 0x24) = (int)sVar3;
        }
        iVar2 = *(int *)(param_1 + 0x24) + -1;
        *(int *)(param_1 + 0x24) = iVar2;
        if (iVar2 < 0) {
          *(undefined4 *)(param_1 + 0x24) = 0;
        }
        param_2 = -(param_2 == 0x67) & 0x65U | 0x45;
      }
    }
    iVar2 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar2 + 1;
    *(undefined1 *)(*(int *)(param_1 + 8) + iVar2) = *param_3;
    if ((0 < *(int *)(param_1 + 0x24)) || ((*(uint *)(param_1 + 0x30) & 8) != 0)) {
      iVar2 = *(int *)(param_1 + 0x14);
      *(int *)(param_1 + 0x14) = iVar2 + 1;
      *(undefined1 *)(*(int *)(param_1 + 8) + iVar2) = 0x2e;
    }
    iVar2 = *(int *)(param_1 + 0x24);
    if (0 < iVar2) {
      iVar4 = param_4 + -1;
      if (iVar2 < (param_4 + -1) * 0x10000 >> 0x10) {
        iVar4 = iVar2;
      }
      iVar2 = (int)(short)iVar4;
      FUN_8000de9c(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14),param_3 + 1,iVar2);
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + iVar2;
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x24) - iVar2;
    }
    pbVar5 = (byte *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14));
    *pbVar5 = param_2;
    if (param_5 << 0x10 < 0) {
      pbVar5[1] = 0x2d;
      param_5._2_2_ = -param_5._2_2_;
    }
    else {
      pbVar5[1] = 0x2b;
    }
    pbVar6 = pbVar5 + 2;
    iVar2 = (int)param_5._2_2_;
    if (99 < iVar2) {
      if (999 < iVar2) {
        *pbVar6 = (char)(iVar2 / 1000) + 0x30;
        pbVar6 = pbVar5 + 3;
        param_5._2_2_ = param_5._2_2_ % 1000;
      }
      *pbVar6 = (char)((int)param_5._2_2_ / 100) + 0x30;
      pbVar6 = pbVar6 + 1;
      param_5._2_2_ = param_5._2_2_ % 100;
    }
    cVar1 = (char)((int)param_5._2_2_ / 10);
    *pbVar6 = cVar1 + 0x30;
    pbVar6[1] = (char)param_5._2_2_ + cVar1 * -10 + 0x30;
    *(byte **)(param_1 + 0x1c) = pbVar6 + (2 - (*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)));
  }
  if (((*(uint *)(param_1 + 0x30) & 0x14) == 0x10) &&
     (iVar2 = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x18) +
              *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x20), iVar2 < *(int *)(param_1 + 0x28))
     ) {
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x28) - iVar2;
  }
  return;
}
