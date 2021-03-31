// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int cnt = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i+1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        cnt++;
      }
    }
  }
  return cnt;
}

int countPairs2(int *arr, int len, int value) {
  int cnt = 0, r = len - 1, l = 0, mid;
  while (l < r - 1) {
    mid = (l + r) / 2;
    if (arr[mid] <= value)
      l = mid + 1;
    else
      r = mid;
  }
  int len2 = r - 1;
  for (int i = len2; i >=0; i--) {
    for (int j = 0; j < i; j++) {
      if (arr[i] + arr[j] == value)
        cnt++;
      if (arr[i] + arr[j] > value)
        break;
    }
  }
  return cnt;
}

int countPairs3(int *arr, int len, int value) {
  int l = 0, r = len - 1, mid, cnt = 0;
  while (l < r - 1) {
    mid = (l + r) / 2;
    if (arr[mid] <= value)
      l = mid + 1;
    else
      r = mid;
  }
  len = r - 1;
  for (int i = 0; i < len - 1; i++) {
    l = i; r = len;
    while (l < r) {
      mid = (l + r) / 2;
      if (arr[mid] < value-arr[i])
        l = mid + 1;
      else
        r = mid;
    }
    int same = r - 1;
    while (arr[same] == value-arr[i]) {
        cnt++;
        same++;
    }
  }
  return cnt;
}
